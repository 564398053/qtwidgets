#include "auto_close_float_tip.h"
#include "toast_widget.h"
#include <QIcon>

void AutoCloseFloatTip::error(QWidget *parent, const QString &txt, bool bModal, int closeDelayMillisecond)
{
    Q_ASSERT(parent);

    auto w = new ToastWidget(txt,
                             QPixmap(":/image/msg_failed_icon@2x.png"),
                             QColor("#FEF0F0"),
                             QColor("#FDE2E2"),
                             QColor("#F85959"),
                             closeDelayMillisecond,
                             parent);
    w->setAttribute(Qt::WA_DeleteOnClose);

    if (bModal) {
        w->exec();
    } else {
        w->show();
    }
}

void AutoCloseFloatTip::success(QWidget *parent, const QString &txt, bool bModal, int closeDelayMillisecond)
{
    Q_ASSERT(parent);

    auto w = new ToastWidget(txt,
                             QPixmap(":/image/msg_success_icon@2x.png"),
                             QColor("#F0F9EB"),
                             QColor("#E1F3D8"),
                             QColor("#42C546"),
                             closeDelayMillisecond,
                             parent);
    w->setAttribute(Qt::WA_DeleteOnClose);

    if (bModal) {
        w->exec();
    } else {
        w->show();
    }
}

void AutoCloseFloatTip::message(QWidget *parent, const QString &txt, bool bModal, int closeDelayMillisecond)
{
    Q_ASSERT(parent);

    auto w = new ToastWidget(txt,
                             QPixmap(""),
                             QColor("rgba(0,0,0,0.8)"),
                             QColor("rgba(0,0,0,0.8)"),
                             QColor("#FFFFFF"),
                             closeDelayMillisecond,
                             parent);
    w->setAttribute(Qt::WA_DeleteOnClose);

    if (bModal) {
        w->exec();
    } else {
        w->show();
    }
}
