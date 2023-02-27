#pragma once

#include <QWidget>

/**
 * 应用程序中的消息弹窗（警告、错误、提示）
 *
 * 使用注意事项
 * 在对话框中使用 AutoCloseFloatTip 时，要将 AutoCloseFloatTip 设置成模态对话框. 
 * 否则父窗口会先于子窗口关闭，子窗口延时关闭时，会导致崩溃.
 * 
 * 显示模态弹窗示例：
 * AutoCloseFloatTip::message(window(), tr("Hey jude"), );
 * 
 * 显示非模态弹窗示例：
 * AutoCloseFloatTip::message(window(), tr("Hey jude"), false);
 */
class  AutoCloseFloatTip
{
public:
    // 错误
    static void error(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 3000);
    // 成功
    static void success(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 2000);
    // 消息
    static void message(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 2000);
};
