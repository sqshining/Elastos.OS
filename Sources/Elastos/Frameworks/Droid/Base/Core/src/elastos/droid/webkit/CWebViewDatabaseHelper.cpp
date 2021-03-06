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

#include "elastos/droid/webkit/CWebViewDatabaseHelper.h"
#include "elastos/droid/webkit/WebViewFactory.h"

namespace Elastos {
namespace Droid {
namespace Webkit {

CAR_INTERFACE_IMPL(CWebViewDatabaseHelper, Object, IWebViewDatabaseHelper);

CAR_SINGLETON_IMPL(CWebViewDatabaseHelper);

ECode CWebViewDatabaseHelper::GetInstance(
    /* [in] */ IContext * pContext,
    /* [out] */ IWebViewDatabase ** ppInstance)
{
    VALIDATE_NOT_NULL(ppInstance);
    WebViewFactory::GetProvider()->GetWebViewDatabase(pContext, ppInstance);
    REFCOUNT_ADD(*ppInstance);
    return NOERROR;
}

} // namespace Webkit
} // namepsace Droid
} // namespace Elastos
