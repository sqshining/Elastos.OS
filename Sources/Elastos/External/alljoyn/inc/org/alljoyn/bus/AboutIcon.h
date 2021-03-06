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

#ifndef __ORG_ALLJOYN_BUS_ABOUTICON_H__
#define __ORG_ALLJOYN_BUS_ABOUTICON_H__

#include "_Org.Alljoyn.Bus.h"
#include <elastos/core/Object.h>

using Elastos::Core::Object;

namespace Org {
namespace Alljoyn {
namespace Bus {

class AboutIcon
    : public Object
    , public IAboutIcon
{
public:
    CAR_INTERFACE_DECL();

    /**
     * Set the content for an icon.  The content must fit into a MsgArg so the
     * largest size for the icon data is MAX_CONTENT_LENGTH bytes.
     *
     * Note as long as the MIME type matches it is possible to set both icon content
     * and icon URL
     *
     * If an error is returned the icon content will remain unchanged.
     *
     * @param mimeType a MIME type indicating the icon image type. Typical
     *                     value will be `image/jpeg` or `image/png`
     * @param content  an array of bytes that represent an icon
     *
     * @throws BusException if unable to create AboutIcon
     * <ul>
     *   <li>"MAX_CONTENT_LENGTH exceeded" if icon is too large</li>
     * </ul>
     */
    CARAPI constructor(
        /* [in] */ const String& mimeType,
        /* [in] */ ArrayOf<Byte>* content);

    /**
     * Set a URL that contains the icon for the application.
     *
     * @param mimeType a MIME type indicating the icon image type. Typical
     *                     value will be `image/jpeg` or `image/png`
     * @param url      A URL that contains the location of the icon hosted in
     *                     the cloud.
     *
     * @throws BusException if unable to create AboutIcon
     */
    CARAPI constructor(
        /* [in] */ const String& mimeType,
        /* [in] */ const String& url);

    /**
     * Set the URL and content for an icon.  The content must fit into a MsgArg so the
     * largest size for the icon data is MAX_CONTENT_LENGTH bytes.
     *
     * Note the MIME type for the content and the URL must match
     *
     * If an error is returned the icon content will remain unchanged.
     *
     * @param mimeType a MIME type indicating the icon image type. Typical
     *                     value will be `image/jpeg` or `image/png`
     * @param url      A URL that contains the location of the icon hosted in
     *                 the cloud.
     * @param content  an array of bytes that represent an icon
     *
     * @throws BusException if unable to create AboutIcon
     * <ul>
     *   <li>"MAX_CONTENT_LENGTH exceeded" if icon is too large</li>
     * </ul>
     */
    CARAPI constructor(
        /* [in] */ const String& mimeType,
        /* [in] */ const String& url,
        /* [in] */ ArrayOf<Byte>* content);

    /**
     * @return A string indicating the image MIME type
     */
    CARAPI GetMimeType(
        /* [out] */ String* mimetype);

    /**
     * @return A URL indicating the cloud location of the icon
     */
    CARAPI GetUrl(
        /* [out] */ String* url);

    /**
     * @return an array of bytes containing the binary content for the icon
     */
    CARAPI GetContent(
        /* [out, callee] */ ArrayOf<Byte>** content);

public:
    /**
     * Max AllJoyn array length and the largest amount of bytes in an About Icon
     */
    static const Int32 MAX_CONTENT_LENGTH = 131072;

private:
    /**
     * the mimetype of the image
     */
    String mMimeType;

    /**
     * The url for the Icon
     */
    String mUrl;

    /**
     * an array of bytes containing the image
     */
    AutoPtr<ArrayOf<Byte> > mContent;
};

} // namespace Bus
} // namespace Alljoyn
} // namespace Org

#endif // __ORG_ALLJOYN_BUS_ABOUTICON_H__
