#include "mainwnd.h"
#include <QVariant>
#include <QPainter>
#include <QDebug>
#include <QPalette>
#include <QApplication>

#include "mainpane.h"


MainWnd::MainWnd(QWidget *parent)
    : QWidget(parent)
{
    m_pMainPane = NULL;
    m_bCloseAnimationState = false;

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    setFixedSize(860, 570);
    setProperty("canMove", "true");
    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式
    setAttribute(Qt::WA_TranslucentBackground, true);
    setProperty("form", "mainwnd");

    GLOBAL_FUNC_RUN
}

MainWnd::~MainWnd()
{

}

void MainWnd::closeEvent(QCloseEvent *event)
{
    if(!m_bCloseAnimationState)
    {
        PlayCloseAnimation();
        event->ignore();
    }
    else{
        event->accept();
    }
}

void MainWnd::CreateAllChildWnd()
{
    NEW_OBJECT(m_pMainPane, MainPane);
}

void MainWnd::InitCtrl()
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    shadow_effect->setBlurRadius(10);

    m_pMainPane->setGraphicsEffect(shadow_effect);
}

void MainWnd::InitSolts()
{
    connect(m_pMainPane, &MainPane::SignalExit, [=]() {
        m_bCloseAnimationState = false;
        close();
    });

    connect(m_pMainPane, &MainPane::SignalMinWindows, [=]() {
        setWindowState(Qt::WindowMinimized);
        update();
    });
}

void MainWnd::Relayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_pMainPane);
    mainLayout->setMargin(10);
    setLayout(mainLayout);
}

void MainWnd::PlayCloseAnimation()
{
    setDisabled(true);
    setMinimumSize(0,0);
    QPropertyAnimation* closeAnimation = new QPropertyAnimation(this,"geometry");
    closeAnimation->setStartValue(geometry());
    closeAnimation->setEndValue(QRect(geometry().x(), geometry().y()+height()/2, width(), 0));
    closeAnimation->setDuration(500);
    m_bCloseAnimationState = true;

    closeAnimation->setEasingCurve(QEasingCurve::OutBounce);  // 缓和曲线风格

    connect(closeAnimation,SIGNAL(finished()),this,SLOT(close()));
    closeAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}
