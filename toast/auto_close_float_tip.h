#pragma once

#include <QWidget>

/**
 * Ӧ�ó����е���Ϣ���������桢������ʾ��
 *
 * ʹ��ע������
 * �ڶԻ�����ʹ�� AutoCloseFloatTip ʱ��Ҫ�� AutoCloseFloatTip ���ó�ģ̬�Ի���. 
 * ���򸸴��ڻ������Ӵ��ڹرգ��Ӵ�����ʱ�ر�ʱ���ᵼ�±���.
 * 
 * ��ʾģ̬����ʾ����
 * AutoCloseFloatTip::message(window(), tr("Hey jude"), );
 * 
 * ��ʾ��ģ̬����ʾ����
 * AutoCloseFloatTip::message(window(), tr("Hey jude"), false);
 */
class  AutoCloseFloatTip
{
public:
    // ����
    static void error(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 3000);
    // �ɹ�
    static void success(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 2000);
    // ��Ϣ
    static void message(QWidget *parent, const QString &txt, bool bModal = true, int closeDelayMillisecond = 2000);
};
