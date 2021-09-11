#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "global.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);

public:
    void SetPixmap(QPixmap pixIcon) { m_pixIcon = pixIcon; update(); }

private:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

signals:
    void SignalSelectImage();
    void SignalClear();

private:
    QPixmap m_pixIcon;
    bool m_bEnter;
};

#endif // CANVAS_H
