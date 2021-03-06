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

#ifndef __ELASTOS_DROID_GOOGLE_MMS_PDU_MULTIMEDIAMESSAGEPDU_H__
#define __ELASTOS_DROID_GOOGLE_MMS_PDU_MULTIMEDIAMESSAGEPDU_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/google/mms/pdu/GenericPdu.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

/**
  * Multimedia message PDU.
  */
class MultimediaMessagePdu
    : public GenericPdu
    , public IMultimediaMessagePdu
{
public:
    CAR_INTERFACE_DECL();

    MultimediaMessagePdu();
    /**
      * Constructor.
      */
    CARAPI constructor();

    /**
      * Constructor.
      *
      * @param header the header of this PDU
      * @param body the body of this PDU
      */
    CARAPI constructor(
        /* [in] */ IPduHeaders* header,
        /* [in] */ IPduBody* body);

    /**
      * Constructor with given headers.
      *
      * @param headers Headers for this PDU.
      */
    CARAPI constructor(
        /* [in] */ IPduHeaders* headers);

    /**
      * Get body of the PDU.
      *
      * @return the body
      */
    virtual CARAPI GetBody(
        /* [out] */ IPduBody** result);

    /**
      * Set body of the PDU.
      *
      * @param body the body
      */
    virtual CARAPI SetBody(
        /* [in] */ IPduBody* body);

    /**
      * Get subject.
      *
      * @return the value
      */
    virtual CARAPI GetSubject(
        /* [out] */ IEncodedStringValue** result);

    /**
      * Set subject.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI SetSubject(
        /* [in] */ IEncodedStringValue* value);

    /**
      * Get To value.
      *
      * @return the value
      */
    virtual CARAPI GetTo(
        /* [out] */ ArrayOf<IEncodedStringValue*>** result);

    /**
      * Add a "To" value.
      *
      * @param value the value
      * @throws NullPointerException if the value is null.
      */
    virtual CARAPI AddTo(
        /* [in] */ IEncodedStringValue* value);

    /**
      * Get X-Mms-Priority value.
      *
      * @return the value
      */
    virtual CARAPI GetPriority(
        /* [out] */ Int32* result);

    /**
      * Set X-Mms-Priority value.
      *
      * @param value the value
      * @throws InvalidHeaderValueException if the value is invalid.
      */
    virtual CARAPI SetPriority(
        /* [in] */ Int32 value);

    /**
      * Get Date value.
      *
      * @return the value
      */
    virtual CARAPI GetDate(
        /* [out] */ Int64* result);

    /**
      * Set Date value in seconds.
      *
      * @param value the value
      */
    virtual CARAPI SetDate(
        /* [in] */ Int64 value);

private:
    /**
      * The body.
      */
    AutoPtr<IPduBody> mMessageBody;
};

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_GOOGLE_MMS_PDU_MULTIMEDIAMESSAGEPDU_H__

