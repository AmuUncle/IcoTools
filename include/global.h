#ifndef GLOBAL_H
#define GLOBAL_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "iconhelper.h"

#include <QtWidgets>

#include <QVBoxLayout>

#include <QDebug>
#include <QtWidgets>
#include <QPainter>
#include <QMouseEvent>

#define VERSION "v1.0"

#define GLOBAL_FUNC \
        void CreateAllChildWnd(); \
        void InitCtrl(); \
        void InitSolts(); \
        void Relayout();

#define GLOBAL_FUNC_RUN \
        CreateAllChildWnd(); \
        InitCtrl(); \
        InitSolts(); \
        Relayout();

#define NEW_OBJECT(pObj, TYPE) \
    if (NULL == pObj) { pObj = new TYPE(this); }

#endif // GLOBAL_H
