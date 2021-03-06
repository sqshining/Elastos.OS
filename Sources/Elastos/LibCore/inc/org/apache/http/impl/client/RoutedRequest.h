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

#ifndef __ORG_APACHE_HTTP_IMPL_CLIENT_ROUTEDREQUEST_H__
#define __ORG_APACHE_HTTP_IMPL_CLIENT_ROUTEDREQUEST_H__

#include "org/apache/http/impl/client/RequestWrapper.h"

using Org::Apache::Http::Conn::Routing::IHttpRoute;

namespace Org {
namespace Apache {
namespace Http {
namespace Impl {
namespace Client {

/**
 * A request with the route along which it should be sent.
 *
 * @author <a href="mailto:rolandw at apache.org">Roland Weber</a>
 *
 *
 * <!-- empty lines to avoid svn diff problems -->
 * @version $Revision: 645846 $
 *
 * @since 4.0
 */
class RoutedRequest : public Object
{
public:
    /**
     * Creates a new routed request.
     *
     * @param req   the request
     * @param route   the route
     */
    RoutedRequest(
        /* [in] */ RequestWrapper* request,
        /* [in] */ IHttpRoute* route);

    CARAPI_(AutoPtr<RequestWrapper>) GetRequest();

    CARAPI_(AutoPtr<IHttpRoute>) GetRoute();

protected:
    AutoPtr<RequestWrapper> mRequest;
    AutoPtr<IHttpRoute> mRoute;
};

} // namespace Client
} // namespace Impl
} // namespace Http
} // namespace Apache
} // namespace Org

#endif // __ORG_APACHE_HTTP_IMPL_CLIENT_ROUTEDREQUEST_H__
