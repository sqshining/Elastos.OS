#include "elastos/droid/server/firewall/AndFilter.h"

namespace Elastos {
namespace Droid {
namespace Server {
namespace Firewall {

//------------------------------------------------------------------------------
// AndFilter::FACTORY_FilterFactory
//------------------------------------------------------------------------------
IFilter* AndFilter::FACTORY_FilterFactory::NewFilter()
    /* in */ IXmlPullParser* parser)
{
    return new AndFilter()->ReadFromXml(parser);
}

//=======================================================================================
// AndFilter
//=======================================================================================
AutoPtr<FACTORY_FilterFactory> AndFilter::FACTORY = new FACTORY_FilterFactory(String("and"));

ECode AndFilter::Matches(
    /* [in] */ IIntentFirewall* ifw,
    /* [in] */ IComponentName* resolvedComponent,
    /* [in] */ IIntent* intent,
    /* [in] */ Int32 callerUid,
    /* [in] */ Int32 callerPid,
    /* [in] */ const String& resolvedType,
    /* [in] */ Int32 receivingUid
    /* [out] */ Boolean *ret)
{
    Int32 size;

    children->GetSize(&size);

    for (Int32 i = 0;  i < size;  i++) {

        AutoPtr<IFilter> filter;
        children->Get(i, (IInterface**)&filter);

        filter->Matches(ifw, resolvedComponent, intent, callerUid, callerPid,
                resolvedType, receivingUid, &ret);
        if (! *ret) {
            return NOERROR;
        }
    }

    *ret = TRUE;
    return NOERROR;
}

} // Firewall
} // Server
} // Droid
} // Elastos