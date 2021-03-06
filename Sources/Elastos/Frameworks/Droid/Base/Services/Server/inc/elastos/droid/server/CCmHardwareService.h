//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_SERVER_CCMHARDWARESERVICE_H__
#define __ELASTOS_DROID_SERVER_CCMHARDWARESERVICE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "Elastos.Droid.Content.h"
#include "_Elastos_Droid_Server_CCmHardwareService.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Hardware::IICmHardwareService;
using Elastos::Droid::Server::ICmHardwareInterface;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace Server {

CarClass(CCmHardwareService)
    , public Object
    , public IICmHardwareService
{
private:
    class LegacyCmHardware
        : public Object
        , public ICmHardwareInterface
    {
    public:
        CAR_INTERFACE_DECL()

        LegacyCmHardware();

        CARAPI GetSupportedFeatures(
            /* [out] */ Int32* result);

        CARAPI Get(
            /* [in] */ Int32 feature,
            /* [out] */ Boolean* result);

        CARAPI Set(
            /* [in] */ Int32 feature,
            /* [in] */ Boolean enable,
            /* [out] */ Boolean* result);

        CARAPI GetDisplayColorCalibration(
            /* [out] */ ArrayOf<Int32>** result);

        CARAPI SetDisplayColorCalibration(
            /* [in] */ ArrayOf<Int32>* rgb,
            /* [out] */ Boolean* result);

        CARAPI GetNumGammaControls(
            /* [out] */ Int32* result);

        CARAPI GetDisplayGammaCalibration(
            /* [in] */ Int32 idx,
            /* [out] */ ArrayOf<Int32>** result);

        CARAPI SetDisplayGammaCalibration(
            /* [in] */ Int32 idx,
            /* [in] */ ArrayOf<Int32>* rgb,
            /* [out] */ Boolean* result);

        CARAPI GetVibratorIntensity(
            /* [out] */ ArrayOf<Int32>** result);

        CARAPI SetVibratorIntensity(
            /* [in] */ Int32 intensity,
            /* [out] */ Boolean* result);

        CARAPI GetLtoSource(
            /* [out] */ String* result);

        CARAPI GetLtoDestination(
            /* [out] */ String* result);

        CARAPI GetLtoDownloadInterval(
            /* [out] */ Int64* result);

        CARAPI GetSerialNumber(
            /* [out] */ String* result);

        CARAPI RequireAdaptiveBacklightForSunlightEnhancement(
            /* [out] */ Boolean* result);

    private:
        CARAPI SplitStringToInt32(
            /* [in] */ String input,
            /* [in] */ String delimiter,
            /* [out] */ ArrayOf<Int32>** result);

        CARAPI RgbToString(
            /* [in] */ ArrayOf<Int32>* rgb,
            /* [out] */ String* result);

    private:
        Int32 mSupportedFeatures;
    };

public:
    CAR_OBJECT_DECL()

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI GetSupportedFeatures(
        /* [out] */ Int32* result);

    CARAPI Get(
        /* [in] */ Int32 feature,
        /* [out] */ Boolean* result);

    CARAPI Set(
        /* [in] */ Int32 feature,
        /* [in] */ Boolean enable,
        /* [out] */ Boolean* result);

    CARAPI GetDisplayColorCalibration(
        /* [out] */ ArrayOf<Int32>** result);

    CARAPI SetDisplayColorCalibration(
        /* [in] */ ArrayOf<Int32>* rgb,
        /* [out] */ Boolean* result);

    CARAPI GetNumGammaControls(
        /* [out] */ Int32* result);

    CARAPI GetDisplayGammaCalibration(
        /* [in] */ Int32 idx,
        /* [out] */ ArrayOf<Int32>** result);

    CARAPI SetDisplayGammaCalibration(
        /* [in] */ Int32 idx,
        /* [in] */ ArrayOf<Int32>* rgb,
        /* [out] */ Boolean* result);

    CARAPI GetVibratorIntensity(
        /* [out] */ ArrayOf<Int32>** result);

    CARAPI SetVibratorIntensity(
        /* [in] */ Int32 intensity,
        /* [out] */ Boolean* result);

    CARAPI GetLtoSource(
        /* [out] */ String* result);

    CARAPI GetLtoDestination(
        /* [out] */ String* result);

    CARAPI GetLtoDownloadInterval(
        /* [out] */ Int64* result);

    CARAPI GetSerialNumber(
        /* [out] */ String* result);

    CARAPI RequireAdaptiveBacklightForSunlightEnhancement(
        /* [out] */ Boolean* result);

private:
    AutoPtr<ICmHardwareInterface> GetImpl(
        /* [in] */ IContext* context);

    Boolean IsSupported(
        /* [in] */ Int32 feature);

private:
    static Boolean DEBUG;
    static String TAG;

    AutoPtr<IContext> mContext;
    AutoPtr<ICmHardwareInterface> mCmHwImpl;
};

} //namespace Server
} //namespace Droid
} //namespace Elastos

#endif //__ELASTOS_DROID_SERVER_CCMHARDWARESERVICE_H__
