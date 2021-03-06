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

#ifndef __ELASTOS_DROID_SYSTEMUI_QS_QSFOOTER_H__
#define __ELASTOS_DROID_SYSTEMUI_QS_QSFOOTER_H__

#include "_Elastos.Droid.SystemUI.h"
#include "Elastos.Droid.App.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.View.h"
#include "Elastos.Droid.Widget.h"
#include <elastos/droid/os/Handler.h>
#include <elastos/core/Runnable.h>
#include <elastos/core/Object.h>

using Elastos::Droid::App::IAlertDialog;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::IDialogInterface;
using Elastos::Droid::Content::IDialogInterfaceOnClickListener;
using Elastos::Droid::Os::Handler;
using Elastos::Core::Runnable;
using Elastos::Droid::SystemUI::StatusBar::Phone::IPhoneQSTileHost;
using Elastos::Droid::SystemUI::StatusBar::Policy::ISecurityController;
using Elastos::Droid::SystemUI::StatusBar::Policy::ISecurityControllerCallback;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::Widget::IImageView;
using Elastos::Droid::Widget::ITextView;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Qs {

class QSFooter
    : public Object
    , public IViewOnClickListener
    , public IDialogInterfaceOnClickListener
{
private:
    class UpdateDisplayState: public Runnable
    {
    public:
        UpdateDisplayState(
            /* [in] */ QSFooter* host);

        // @Override
        CARAPI Run();

    private:
        QSFooter* mHost;
    };

    class Callback
        : public Object
        , public ISecurityControllerCallback
    {
    public:
        CAR_INTERFACE_DECL()

        Callback(
            /* [in] */ QSFooter* host);

        // @Override
        CARAPI OnStateChanged();

    private:
        QSFooter* mHost;
    };

    class H: public Handler
    {
    public:
        TO_STRING_IMPL("QSFooter::H")

        H(
            /* [in] */ ILooper* looper,
            /* [in] */ QSFooter* host);

        // @Override
        CARAPI HandleMessage(
            /* [in] */ IMessage* msg);

    public:
        static const Int32 CLICK;
        static const Int32 REFRESH_STATE;

    private:
        QSFooter* mLocalHost;
    };

    class QSFooterClickListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        CAR_INTERFACE_DECL()

        QSFooterClickListener(
            /* [in] */ QSFooter* host);

        // @Override
        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        QSFooter* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    QSFooter(
        /* [in] */ IQSPanel* qsPanel,
        /* [in] */ IContext* context);

    CARAPI_(void) SetHost(
        /* [in] */ IPhoneQSTileHost* host);

    CARAPI_(void) SetListening(
        /* [in] */ Boolean listening);

    virtual CARAPI OnConfigurationChanged();

    CARAPI_(AutoPtr<IView>) GetView();

    CARAPI_(Boolean) HasFooter();

    // @Override
    CARAPI OnClick(
        /* [in] */ IView* v);

    CARAPI_(void) RefreshState();

    // @Override
    CARAPI OnClick(
        /* [in] */ IDialogInterface* dialog,
        /* [in] */ Int32 which);

private:
    CARAPI HandleClick();

    CARAPI HandleRefreshState();

    CARAPI_(void) CreateDialog();

    CARAPI_(String) GetNegativeButton();

    CARAPI_(String) GetPositiveButton();

    CARAPI_(String) GetMessage();

    CARAPI_(Int32) GetTitle();

protected:
    static const String TAG;
    static const Boolean DEBUG;

private:
    AutoPtr<IView> mRootView;
    AutoPtr<ITextView> mFooterText;
    AutoPtr<IImageView> mFooterIcon;
    AutoPtr<IContext> mContext;
    AutoPtr<Callback> mCallback;

    AutoPtr<ISecurityController> mSecurityController;
    AutoPtr<IAlertDialog> mDialog;
    AutoPtr<IPhoneQSTileHost> mHost;
    AutoPtr<IHandler> mHandler;
    AutoPtr<IHandler> mMainHandler;

    Boolean mIsVisible;
    Boolean mIsIconVisible;
    Int32 mFooterTextId;
    AutoPtr<IRunnable> mUpdateDisplayState;
};

} // namespace Qs
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_QS_QSFOOTER_H__
