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

#include "elastos/droid/wifi/p2p/nsd/CWifiP2pUpnpServiceRequest.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/wifi/p2p/nsd/CWifiP2pServiceRequest.h"
#include "elastos/droid/wifi/p2p/nsd/CWifiP2pServiceInfo.h"
#include "elastos/droid/wifi/p2p/nsd/WifiP2pServiceInfo.h"
#include <elastos/utility/logging/Slogger.h>

using Elastos::Utility::Logging::Slogger;

namespace Elastos {
namespace Droid {
namespace Wifi {
namespace P2p {
namespace Nsd {

CAR_OBJECT_IMPL(CWifiP2pUpnpServiceRequest)

ECode CWifiP2pUpnpServiceRequest::constructor()
{
    return WifiP2pServiceRequest::constructor(
        IWifiP2pServiceInfo::SERVICE_TYPE_UPNP, String(NULL));
}

ECode CWifiP2pUpnpServiceRequest::constructor(
    /* [in] */ const String& query)
{
    return WifiP2pServiceRequest::constructor(
        IWifiP2pServiceInfo::SERVICE_TYPE_UPNP, query);
}

ECode CWifiP2pUpnpServiceRequest::GetTransactionId(
    /* [out] */ Int32* transactionId)
{
    return WifiP2pServiceRequest::GetTransactionId(transactionId);
}

ECode CWifiP2pUpnpServiceRequest::SetTransactionId(
    /* [in] */ Int32 id)
{
    return WifiP2pServiceRequest::SetTransactionId(id);
}

ECode CWifiP2pUpnpServiceRequest::GetSupplicantQuery(
    /* [out] */ String* supplicantQuery)
{
    return WifiP2pServiceRequest::GetSupplicantQuery(supplicantQuery);
}

ECode CWifiP2pUpnpServiceRequest::Equals(
    /* [in] */ IInterface* obj,
    /* [out] */ Boolean* isEqual)
{
    return WifiP2pServiceRequest::Equals(obj, isEqual);
}

ECode CWifiP2pUpnpServiceRequest::GetHashCode(
    /* [out] */ Int32 * hashCode)
{
    return WifiP2pServiceRequest::GetHashCode(hashCode);
}

ECode CWifiP2pUpnpServiceRequest::ReadFromParcel(
    /* [in] */ IParcel* source)
{
    return WifiP2pServiceRequest::ReadFromParcel(source);
}

ECode CWifiP2pUpnpServiceRequest::WriteToParcel(
    /* [in] */ IParcel* dest)
{
    return WifiP2pServiceRequest::WriteToParcel(dest);
}

ECode CWifiP2pUpnpServiceRequest::NewInstance(
    /* [out] */ IWifiP2pUpnpServiceRequest** instance)
{
    return CWifiP2pUpnpServiceRequest::New(instance);
}

ECode CWifiP2pUpnpServiceRequest::NewInstance(
    /* [in] */ const String& st,
    /* [out] */ IWifiP2pUpnpServiceRequest** instance)
{
    VALIDATE_NOT_NULL(instance);
    *instance = NULL;

    if (st.IsNull()) {
        Slogger::E("CWifiP2pUpnpServiceRequest", "search target cannot be null");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    String sb;
    assert(0);
    // TODO
    // FAIL_RETURN(sb.AppendFormat(Locale.US,"%02x", IWifiP2pUpnpServiceInfo::VERSION_1_0));
    String temp;
    FAIL_RETURN(WifiP2pServiceInfo::Bin2HexStr(st.string(), st.GetByteLength(), &temp));
    sb += temp;

    return CWifiP2pUpnpServiceRequest::New(sb, instance);
}

} // namespace Nsd
} // namespace P2p
} // namespace Wifi
} // namespace Droid
} // namespace Elastos
