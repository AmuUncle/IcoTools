#include "about.h"

About::About(QWidget *parent) :
    QDialog(parent)
{

    setWindowFlags(windowFlags() | (Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::Dialog));


    setProperty("form", "About");
    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式

    GLOBAL_FUNC_RUN

}

About::~About()
{

}

void About::CreateAllChildWnd()
{

}

void About::InitCtrl()
{
    setFixedSize(400, 250);
}

void About::InitSolts()
{

}

void About::Relayout()
{

}
