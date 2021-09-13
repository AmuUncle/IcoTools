#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    m_bEnter = false;

    setProperty("form", "Canvas");
    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式

    setAcceptDrops(true);
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
    for (int nRow = 0; nRow < (height() / 20 + 1); nRow++)
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
        painter.setBrush(m_colorEmptyBg);
        painter.drawRect(rcImg);

        QColor colorFlag(m_colorSelColor);

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
        painter.drawText(rcText, Qt::AlignHCenter | Qt::AlignTop, tr("点击上传图片，也可拖曳添加图片\r\n 支持JPG、JPEG、PNG、BMP、ICO格式图片转换"));

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

void Canvas::dragEnterEvent(QDragEnterEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
    {
        event->ignore();
        return;
    }

    QFileInfo fileinfo = QFileInfo(urls[0].toString());
    QString suffix = fileinfo.suffix();

    if(!suffix.compare("jpg") || !suffix.compare("png") || !suffix.compare("ico") || !suffix.compare("jpeg") || !suffix.compare("bmp"))
        event->acceptProposedAction();
     else
        event->ignore();
}

void Canvas::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
    {
        return;
    }

    emit SignalDropImageChange(urls[0].toLocalFile());
}
