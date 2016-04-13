
#include "CProximitySensorManager.h"

namespace Elastos{
namespace Apps{
namespace Dialer {

const Float CProximitySensorManager::ProximitySensorEventListener::FAR_THRESHOLD = 5.0f;

//=================================================================
// CProximitySensorManager::ProximitySensorEventListener
//=================================================================
CAR_INTERFACE_IMPL(CProximitySensorManager::ProximitySensorEventListener, Object, ISensorEventListener)

CProximitySensorManager::ProximitySensorEventListener::ProximitySensorEventListener(
    /* [in] */ ISensorManager* sensorManager,
    /* [in] */ ISensor* proximitySensor,
    /* [in] */ IProximitySensorManagerListener* listener)
    : mLastState(IProximitySensorManager::State.FAR)
    , mWaitingForFarState(FALSE)
{
    mSensorManager = sensorManager;
    mProximitySensor = proximitySensor;
    proximitySensor->GetMaximumRange(&mMaxValue);
    mListener = listener;
}

ECode CProximitySensorManager::ProximitySensorEventListener::OnSensorChanged(
    /* [in] */ ISensorEvent* event)
{
    // Make sure we have a valid value.
    AutoPtr<ArrayOf<Float> > values;
    event->GetValues((ArrayOf<Float>**)&values);
    if (values == NULL) {
        return NOERROR;
    }

    if (values->GetLength() == 0) {
        return NOERROR;
    }

    Float value = (*values)[0];
    // Convert the sensor into a NEAR/FAR state.
    IProximitySensorManager::State state = GetStateFromValue(value);
    synchronized(this) {
        // No change in state, do nothing.
        if (state == mLastState) {
            return NOERROR;
        }
        // Keep track of the current state.
        mLastState = state;
        // If we are waiting to reach the far state and we are now in it, unregister.
        if (mWaitingForFarState && mLastState == IProximitySensorManager::State.FAR) {
            UnregisterWithoutNotification();
        }
    }
    // Notify the listener of the state change.
    switch (state) {
        case IProximitySensorManager::State.NEAR:
            mListener->OnNear();
            break;

        case IProximitySensorManager::State.FAR:
            mListener->OnFar();
            break;
    }

    return NOERROR;
}

ECode CProximitySensorManager::ProximitySensorEventListener::OnAccuracyChanged(
    /* [in] */ ISensor* sensor,
    /* [in] */ Int32 accuracy)
{
    // Nothing to do here.
    return NOERROR;
}

IProximitySensorManager::State CProximitySensorManager::ProximitySensorEventListener::GetStateFromValue(
    /* [in] */ Float value)
{
     // Determine if the current value corresponds to the NEAR or FAR state.
    // Take case of the case where the proximity sensor is binary: if the current value is
    // equal to the maximum, we are always in the FAR state.
    return (value > FAR_THRESHOLD || value == mMaxValue)
            ? IProximitySensorManager::State.FAR : IProximitySensorManager::State.NEAR;
}

void CProximitySensorManager::ProximitySensorEventListener::UnregisterWhenFar()
{
    synchronized(this) {
        if (mLastState == State.FAR) {
            // We are already in the far state, just unregister now.
            UnregisterWithoutNotification();
        }
        else {
            mWaitingForFarState = TRUE;
        }
    }
}

void CProximitySensorManager::ProximitySensorEventListener::Register()
{
    synchronized(this) {
        // It is okay to register multiple times.
        Boolean supported;
        mSensorManager->RegisterListener(ISensorListener::Probe(this),
                mProximitySensor, ISensorManager::SENSOR_DELAY_UI, &supported);
        // We should no longer be waiting for the far state if we are registering again.
        mWaitingForFarState = FALSE;
    }
}

void CProximitySensorManager::ProximitySensorEventListener::Unregister()
{
    IProximitySensorManager::State lastState;
    synchronized(this) {
        UnregisterWithoutNotification();
        lastState = mLastState;
        // Always go back to the FAR state. That way, when we register again we will get a
        // transition when the sensor gets into the NEAR state.
        mLastState = IProximitySensorManager::State.FAR;
    }
    // Notify the listener if we changed the state to FAR while unregistering.
    if (lastState != IProximitySensorManager::State.FAR) {
        mListener->OnFar();
    }
}

void CProximitySensorManager::ProximitySensorEventListener::UnregisterWithoutNotification()
{
    mSensorManager->UnregisterListener(ISensorListener::Probe(this));
    mWaitingForFarState = FALSE;
}

//=================================================================
// CProximitySensorManager
//=================================================================
CAR_INTERFACE_IMPL(CProximitySensorManager, Object, IProximitySensorManager)

CAR_OBJECT_IMPL(CProximitySensorManager)

CProximitySensorManager::CProximitySensorManager()
    : mManagerEnabled(FALSE)
{}

ECode CProximitySensorManager::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IProximitySensorManagerListener* listener)
{
    AutoPtr<IInterface> service;
    context->GetSystemService(IContext::SENSOR_SERVICE, (IInterface**)&service);
    ISensorManager* sensorManager = ISensorManager::Probe(service);

    AutoPtr<ISensor> proximitySensor;
    sensorManager->GetDefaultSensor(ISensor::TYPE_PROXIMITY, (ISensor**)&proximitySensor);
    if (proximitySensor == NULL) {
        // If there is no sensor, we should not do anything.
        mProximitySensorListener = NULL;
    }
    else {
        mProximitySensorListener =
                new ProximitySensorEventListener(sensorManager, proximitySensor, listener);
    }

    return NOERROR;
}

ECode CProximitySensorManager::Enable()
{
    if (mProximitySensorListener != NULL && !mManagerEnabled) {
        mProximitySensorListener->Register();
        mManagerEnabled = TRUE;
    }

    return NOERROR;
}

ECode CProximitySensorManager::Disable(
        /* [in] */ Boolean waitForFarState)
{
    if (mProximitySensorListener != NULL && mManagerEnabled) {
        if (waitForFarState) {
            mProximitySensorListener->UnregisterWhenFar();
        }
        else {
            mProximitySensorListener->Unregister();
        }
        mManagerEnabled = FALSE;
    }
    return NOERROR;
}

} // Dialer
} // Apps
} // Elastos