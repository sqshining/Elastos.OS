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

//This file is autogenerated for
//    BatteryStatusManager.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_BATTERYSTATUSMANAGER_CALLBACK_DEC_HH
#define ELASTOS_BATTERYSTATUSMANAGER_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_BatteryStatusManager_nativeGotBatteryStatus(IInterface* caller,Handle64 nativeBatteryStatusManager,Boolean charging,Double chargingTime,Double dischargingTime,Double level);
    extern void Elastos_BatteryStatusManager_InitCallback(Handle64 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Browser {

struct ElaBatteryStatusManagerCallback
{
    AutoPtr<IInterface> (*elastos_BatteryStatusManager_getInstance)(IInterface* appContext);
    Boolean (*elastos_BatteryStatusManager_start)(IInterface* obj, Handle64 nativePtr);
    void (*elastos_BatteryStatusManager_stop)(IInterface* obj);
};

void* BatteryStatusManager::ElaBatteryStatusManagerCallback_Init()
{
    static ElaBatteryStatusManagerCallback sElaBatteryStatusManagerCallback;

    sElaBatteryStatusManagerCallback.elastos_BatteryStatusManager_getInstance = &BatteryStatusManager::GetInstance;
    sElaBatteryStatusManagerCallback.elastos_BatteryStatusManager_start = &BatteryStatusManager::Start;
    sElaBatteryStatusManagerCallback.elastos_BatteryStatusManager_stop = &BatteryStatusManager::Stop;

    Elastos_BatteryStatusManager_InitCallback((Handle64)&sElaBatteryStatusManagerCallback);
    return &sElaBatteryStatusManagerCallback;
}

static void* sPElaBatteryStatusManagerCallback = BatteryStatusManager::ElaBatteryStatusManagerCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_BATTERYSTATUSMANAGER_CALLBACK_DEC_HH
