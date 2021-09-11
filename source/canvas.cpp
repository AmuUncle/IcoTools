#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_bEnter = false;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);         // 创建画家对象
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform | QPainter::Qt4CompatiblePainting);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#fff"));
    painter.drawRect(rect());


    painter.save();
    painter.setBrush(QColor("#E9E9E9"));
    for (int nRow = 0; nRow < height() / 20; nRow++)
    {
        for (int nCol = 0; nCol < width() / 20; nCol++)
        {
            if (nRow % 2 != 0)
            {
                if (nCol % 2 != 0)
                {
                    painter.drawRect(nCol * 20, nRow * 20, 20, 20);
                }
            }
            else
            {
                if (nCol % 2 == 0)
                {
                    painter.drawRect(nCol * 20, nRow * 20, 20, 20);
                }
            }
        }
    }
    painter.restore();

    if (!m_pixIcon.isNull())
    {
        QRect rcImg(10, (height() - (width() - 20)) / 2, width() - 20, width() - 20);
        QPixmap p = m_pixIcon.scaled(rcImg.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter.drawPixmap(rcImg, p);

#ifdef CAN_REMOVE
        if (m_bEnter)
        {
            painter.setPen(Qt::NoPen);
            QColor maskColor = QColor("#fff");
            maskColor.setAlpha(220);
            painter.setBrush(maskColor);
            painter.drawRect(rcImg);

            painter.save();
            QFont font = IconHelper::GetFont();
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(QColor("#F00"));
            painter.drawText(rcImg, Qt::AlignCenter, QChar(0xe769));

            painter.restore();
        }
#endif

    }
    else
    {
        QRect rcImg(10, (height() - (width() - 20)) / 2, width() - 20, width() - 20);

        painter.save();
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor("#2B2B2B"));
        painter.drawRect(rcImg);

        QColor colorFlag("#b0b8d5");

        if (m_bEnter)
            colorFlag = Qt::white;

        QPen pen(colorFlag, 1, Qt::DashLine);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(rcImg.marginsRemoved(QMargins(1, 1, 1, 1)));

        const int LINE = 120;
        painter.drawLine(rcImg.left() + rcImg.width() / 2,
                         rcImg.top() + (rcImg.height() - LINE) / 2,
                         rcImg.left() + rcImg.width() / 2,
                         rcImg.top() + (rcImg.height() - LINE) / 2 + LINE);

        painter.drawLine(rcImg.left() + (rcImg.width() - LINE) / 2,
                         rcImg.top() + rcImg.height() / 2,
                         rcImg.left() + (rcImg.width() - LINE) / 2 + LINE,
                         rcImg.top() + rcImg.height() / 2);

        QRect rcText(rcImg);
        rcText.setTop(rcImg.top() + (rcImg.height() - LINE) / 2 + LINE + 10);
        painter.drawText(rcText, Qt::AlignHCenter | Qt::AlignTop, tr("选择图像"));

        painter.restore();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
#ifdef CAN_REMOVE
    if (!m_pixIcon.isNull())
        emit SignalClear();
    else
        emit SignalSelectImage();
#else
    emit SignalSelectImage();
#endif
}

void Canvas::enterEvent(QEvent *event)
{
    m_bEnter = true;
    update();
}

void Canvas::leaveEvent(QEvent *event)
{
    m_bEnter = false;
    update();
}
