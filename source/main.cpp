#include "mainwnd.h"
#include <QApplication>
#include <QFontDatabase>
#include <QFile>
#include "iconhelper.h"
#include "appinit.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));

    AppInit::Instance()->start();
    IconHelper::Load();

    //更改程序启动后任务栏图标
    a.setWindowIcon(QIcon(":/img/img/icon.png"));

    //加载样式表
    QFile file(":/css/css/style.css");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }

    MainWnd w;
    w.show();

    return a.exec();
}
