#ifndef MAINWND_H
#define MAINWND_H

#include <QWidget>
#include <QStackedWidget>

#include "global.h"

class MainPane;

class MainWnd : public QWidget
{
    Q_OBJECT

public:
    MainWnd(QWidget *parent = 0);
    ~MainWnd();

private:
    GLOBAL_FUNC

    void closeEvent(QCloseEvent *event);
    void PlayCloseAnimation();

private:
    MainPane *m_pMainPane;

    bool m_bCloseAnimationState;
};

#endif // MAINWND_H
