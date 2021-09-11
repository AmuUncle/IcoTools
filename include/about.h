#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "boderpane.h"
#include "global.h"


class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private:
    GLOBAL_FUNC
};

#endif // ABOUT_H
