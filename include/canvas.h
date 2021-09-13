#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "global.h"

class Canvas : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor colorEmptyBg WRITE SetEmptyBgColor)
    Q_PROPERTY(QColor colorSelColor WRITE SetSelColor)

public:
    explicit Canvas(QWidget *parent = 0);

public:
    void SetPixmap(QPixmap pixIcon) { m_pixIcon = pixIcon; update(); }

    void SetEmptyBgColor(QColor color) { m_colorEmptyBg = color; update(); }
    void SetSelColor(QColor color) { m_colorSelColor = color; update(); }

private:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

signals:
    void SignalSelectImage();
    void SignalClear();
    void SignalDropImageChange(QString imgPath);

private:
    QPixmap m_pixIcon;
    bool m_bEnter;

    QColor m_colorEmptyBg;
    QColor m_colorSelColor;
};

#endif // CANVAS_H
