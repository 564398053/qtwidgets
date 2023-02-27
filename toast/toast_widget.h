#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QDesktopWidget>
#include <QScreen>
#include <QGuiApplication>
#include <QDialog>

class ToastWidget : public QDialog
{
public:
    ToastWidget(const QString &message,
                const QPixmap &icon,
                const QColor &backgroundColor,
                const QColor &borderColor,
                const QColor &textColor,
                int closeDelay = 3000,
                QWidget *parent = nullptr)
        : QDialog(parent)
        , m_backgroundColor(backgroundColor)
        , m_borderColor(borderColor)
        , m_textColor(textColor)
        , m_timer(new QTimer(this))
    {
        QHBoxLayout *layout = new QHBoxLayout(this);
        QWidget *container = new QWidget(this);
        QHBoxLayout *containerLayout = new QHBoxLayout(container);

        QLabel *iconLabel = new QLabel(container);
        iconLabel->setScaledContents(true);
        iconLabel->setMaximumSize(QSize(32, 32));
        iconLabel->setPixmap(icon);
        containerLayout->addWidget(iconLabel, 0, Qt::AlignVCenter | Qt::AlignHCenter);

        QLabel *messageLabel = new QLabel(message, container);
        messageLabel->setStyleSheet(QString("font-size: 14px; color:%1;").arg(m_textColor.name()));

        containerLayout->addWidget(messageLabel, 1, Qt::AlignLeft | Qt::AlignVCenter);
        containerLayout->setContentsMargins(24, 0, 24, 0);
        containerLayout->setSpacing(6);
        container->setLayout(containerLayout);

        layout->addWidget(container);
        layout->setContentsMargins(0, 0, 0, 0);

        setLayout(layout);
        setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
        setAttribute(Qt::WA_TranslucentBackground);

        m_timer->setSingleShot(true);

        connect(m_timer, &QTimer::timeout, this, &QWidget::close);
        m_timer->start(closeDelay);

        if (icon.isNull()) {
            // 没有图标则隐藏
            iconLabel->setVisible(false);
            messageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        } else {
            messageLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        }

        // 居中
        adjustSize();
        setFixedHeight(42);
        QRect parentGeometry;
        QWidget *parentWidget = nativeParentWidget();
        if (parentWidget == nullptr) {
            QPoint cursorPos = QCursor::pos();
            QScreen *screen = QGuiApplication::screenAt(cursorPos);
            parentGeometry = screen->availableGeometry();
        } else {
            parentGeometry = parentWidget->geometry();
        }

        int x = (parentGeometry.width() - width()) / 2;
        int y = (parentGeometry.height() - height()) / 2;
        move(x, y);
    }

    void setBackgroundColor(const QColor &color)
    {
        m_backgroundColor = color;
        update();
    }

    void setBorderColor(const QColor &color)
    {
        m_borderColor = color;
        update();
    }

    void setTextColor(const QColor &color)
    {
        m_textColor = color;
        foreach (QLabel *label, findChildren<QLabel *>()) {
            label->setStyleSheet(QString("font-size: 14px; color:%1;").arg(m_textColor.name()));
        }
    }

    virtual ~ToastWidget()
    {
        m_timer->stop();
        delete m_timer;
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);
        painter.setBrush(m_backgroundColor);
        painter.drawRoundedRect(rect(), 4, 4);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(m_borderColor, 1));
        painter.drawRoundedRect(rect(), 4, 4);
    }

    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            m_timer->stop();
            close();
        }
    }

private:
    QColor m_backgroundColor;
    QColor m_borderColor;
    QColor m_textColor;
    QTimer *m_timer;
};