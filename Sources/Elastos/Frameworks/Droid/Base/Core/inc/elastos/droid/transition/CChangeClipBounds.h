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

#ifndef __ELASTOS_DROID_TRANSITION_CCHANGECLIPBOUNDS_H__
#define __ELASTOS_DROID_TRANSITION_CCHANGECLIPBOUNDS_H__

#include "_Elastos_Droid_Transition_CChangeClipBounds.h"
#include "elastos/droid/transition/Transition.h"

namespace Elastos {
namespace Droid {
namespace Transition {

/**
 * ChangeClipBounds captures the {@link android.view.View#getClipBounds()} before and after the
 * scene change and animates those changes during the transition.
 */
CarClass(CChangeClipBounds)
    , public Transition
{
public:
    CAR_OBJECT_DECL()

    CChangeClipBounds();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI GetTransitionProperties(
        /* [out, callee] */ ArrayOf<String>** result);

    CARAPI CaptureStartValues(
        /* [in] */ ITransitionValues* transitionValues);

    CARAPI CaptureEndValues(
        /* [in] */ ITransitionValues* transitionValues);

    CARAPI CreateAnimator(
        /* [in] */ IViewGroup* sceneRoot,
        /* [in] */ ITransitionValues* startValues,
        /* [in] */ ITransitionValues* endValues,
        /* [out] */ IAnimator** result);

    CARAPI Clone(
        /* [out] */ IInterface** obj);

    CARAPI CloneImpl(
        /* [in] */ ITransition* obj);

private:
    using Transition::CaptureValues;

    CARAPI_(void) CaptureValues(
        /* [in] */ ITransitionValues* values);

private:
    static const String TAG;

    static const String PROPNAME_CLIP;
    static const String PROPNAME_BOUNDS;

    static AutoPtr<ArrayOf<String> > sTransitionProperties;
};

} // namespace Transition
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_TRANSITION_CCHANGECLIPBOUNDS_H__
