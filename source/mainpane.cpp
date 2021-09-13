#include "mainpane.h"
#include "canvas.h"
#include "about.h"


MainPane::MainPane(QWidget *parent) : QWidget(parent)
{
    m_wTitlePane = NULL;
    m_labelLogo = NULL;
    m_labelTitle = NULL;
    m_btnMin = NULL;
    m_btnClose = NULL;
    m_btnAbout = NULL;


    m_wLeftPane = NULL;
    m_btnShape1 = NULL;
    m_btnShape2 = NULL;
    m_btnShape3 = NULL;
    m_btnShape4 = NULL;
    m_btnShape5 = NULL;
    m_btnShape6 = NULL;
    m_btnShape7 = NULL;
    m_btnShape8 = NULL;
    m_btnShape9 = NULL;

    m_wContentPane = NULL;
    m_pCanvas = NULL;


    m_wRightPane = NULL;
    m_labelPadding = NULL;
    m_sliderPadding = NULL;
    m_labelBackgroud = NULL;
    m_labelSeparator1 = NULL;
    m_labelR = NULL;
    m_sliderR = NULL;
    m_labelRV = NULL;
    m_labelG = NULL;
    m_sliderG = NULL;
    m_labelGV = NULL;
    m_labelB = NULL;
    m_sliderB = NULL;
    m_labelBV = NULL;
    m_labelA = NULL;
    m_sliderA = NULL;
    m_labelAV = NULL;
    m_labelSeparator2 = NULL;
    m_labelOpacity = NULL;
    m_sliderOpacity = NULL;
    m_labelOpacityV = NULL;

    m_wBottomPane = NULL;
    m_btnReset = NULL;
    m_labelFormat = NULL;
    m_comboxFormat = NULL;
    m_labelSize = NULL;
    m_comboxSize = NULL;
    m_btnExport = NULL;

    m_pAboutdlg = NULL;

    m_nBorderRadius = 0;
    m_nPadding = 0;
    m_colorBg = QColor(255, 255, 255, 255);
    m_nOpacity = 100;

    setAttribute(Qt::WA_StyledBackground);  // 禁止父窗口样式影响子控件样式
    setProperty("form", "mainpane");

    GLOBAL_FUNC_RUN
}

void MainPane::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
}

void MainPane::InitLeftPane()
{
    m_btnShape1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnShape9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_btnShape1->setProperty("shape_btn", true);
    m_btnShape2->setProperty("shape_btn", true);
    m_btnShape3->setProperty("shape_btn", true);
    m_btnShape4->setProperty("shape_btn", true);
    m_btnShape5->setProperty("shape_btn", true);
    m_btnShape6->setProperty("shape_btn", true);
    m_btnShape7->setProperty("shape_btn", true);
    m_btnShape8->setProperty("shape_btn", true);
    m_btnShape9->setProperty("shape_btn", true);

    QString strColor = "#5768a4";
    m_btnShape1->setIcon(QIcon(GetPixmap(strColor, 50, 50, 0)));
    m_btnShape1->setIconSize(QSize(50, 50));
    m_btnShape2->setIcon(QIcon(GetPixmap(strColor, 50, 50, 3)));
    m_btnShape2->setIconSize(QSize(50, 50));
    m_btnShape3->setIcon(QIcon(GetPixmap(strColor, 50, 50, 6)));
    m_btnShape3->setIconSize(QSize(50, 50));
    m_btnShape4->setIcon(QIcon(GetPixmap(strColor, 50, 50, 9)));
    m_btnShape4->setIconSize(QSize(50, 50));
    m_btnShape5->setIcon(QIcon(GetPixmap(strColor, 50, 50, 12)));
    m_btnShape5->setIconSize(QSize(50, 50));
    m_btnShape6->setIcon(QIcon(GetPixmap(strColor, 50, 50, 15)));
    m_btnShape6->setIconSize(QSize(50, 50));
    m_btnShape7->setIcon(QIcon(GetPixmap(strColor, 50, 50, 18)));
    m_btnShape7->setIconSize(QSize(50, 50));
    m_btnShape8->setIcon(QIcon(GetPixmap(strColor, 50, 50, 22)));
    m_btnShape8->setIconSize(QSize(50, 50));
    m_btnShape9->setIcon(QIcon(GetPixmap(strColor, 50, 50, 25)));
    m_btnShape9->setIconSize(QSize(50, 50));

    QSignalMapper *pSignalMapperPushed = new QSignalMapper(this);
    pSignalMapperPushed->setMapping(m_btnShape1, 0);
    pSignalMapperPushed->setMapping(m_btnShape2, 12);
    pSignalMapperPushed->setMapping(m_btnShape3, 18);
    pSignalMapperPushed->setMapping(m_btnShape4, 24);
    pSignalMapperPushed->setMapping(m_btnShape5, 32);
    pSignalMapperPushed->setMapping(m_btnShape6, 48);
    pSignalMapperPushed->setMapping(m_btnShape7, 56);
    pSignalMapperPushed->setMapping(m_btnShape8, 68);
    pSignalMapperPushed->setMapping(m_btnShape9, 100);

    QList<QPushButton *> listBtns = findChildren<QPushButton *>();
    foreach (QPushButton *btn, listBtns)
    {
        if (!btn->property("shape_btn").toBool())
            continue;

        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(OnLeftBtnsClick()));
        connect(btn, SIGNAL(clicked()), pSignalMapperPushed, SLOT(map()));
    }

    connect(pSignalMapperPushed, static_cast<void (QSignalMapper::*)(int)>(&QSignalMapper::mapped), [=](int value)
    {
        m_nBorderRadius = value;
        UpdatePixmap();
    });

    m_btnShape1->setChecked(true);
}

void MainPane::InitRightPane()
{
    m_labelSeparator1->setProperty("Separator", true);
    m_labelSeparator2->setProperty("Separator", true);

    m_labelSeparator1->setFixedHeight(1);
    m_labelSeparator2->setFixedHeight(1);

    m_labelPadding->setText(tr("填充"));

    m_sliderPadding->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderPadding->setMinimum(0);  // 最小值
    m_sliderPadding->setMaximum(100);  // 最大值

    m_labelBackgroud->setText(tr("背景颜色"));
    m_labelR->setText(tr("R"));
    m_labelG->setText(tr("G"));
    m_labelB->setText(tr("B"));
    m_labelA->setText(tr("A"));

    m_sliderR->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderR->setMinimum(0);  // 最小值
    m_sliderR->setMaximum(255);  // 最大值
    m_sliderR->setValue(255);
    m_sliderG->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderG->setMinimum(0);  // 最小值
    m_sliderG->setMaximum(255);  // 最大值
    m_sliderG->setValue(255);
    m_sliderB->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderB->setMinimum(0);  // 最小值
    m_sliderB->setMaximum(255);  // 最大值
    m_sliderB->setValue(255);
    m_sliderA->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderA->setMinimum(0);  // 最小值
    m_sliderA->setMaximum(255);  // 最大值
    m_sliderA->setValue(255);

    m_labelOpacity->setText(tr("透明度"));
    m_sliderOpacity->setOrientation(Qt::Horizontal);  // 水平方向
    m_sliderOpacity->setMinimum(0);  // 最小值
    m_sliderOpacity->setMaximum(100);  // 最大值
    m_sliderOpacity->setValue(100);

    connect(m_sliderPadding, &QSlider::valueChanged, [=](int value)
    {
        m_nPadding = value;
        UpdatePixmap();
    });

    connect(m_sliderR, &QSlider::valueChanged, [=](int value)
    {
        m_colorBg.setRed(value);
        UpdatePixmap();
    });

    connect(m_sliderG, &QSlider::valueChanged, [=](int value)
    {
        m_colorBg.setGreen(value);
        UpdatePixmap();
    });

    connect(m_sliderB, &QSlider::valueChanged, [=](int value)
    {
        m_colorBg.setBlue(value);
        UpdatePixmap();
    });

    connect(m_sliderA, &QSlider::valueChanged, [=](int value)
    {
        m_colorBg.setAlpha(value);
        UpdatePixmap();
    });


    connect(m_sliderOpacity, &QSlider::valueChanged, [=](int value)
    {
        m_nOpacity = value;
        UpdatePixmap();
    });
}

void MainPane::InitBottomPane()
{
    m_btnReset->setText(tr("重新选择"));
    m_labelFormat->setText(tr("格式:"));
    m_labelSize->setText(tr("大小:"));
    m_labelFormat->setFixedHeight(26);
    m_labelSize->setFixedHeight(26);

    m_btnReset->setObjectName("m_btnExport");
    m_btnReset->setFixedSize(100, 26);
    m_btnExport->setObjectName("m_btnExport");
    m_btnExport->setFixedSize(100, 26);
    m_btnExport->setText(tr("导出"));

    m_comboxFormat->setFixedSize(100, 26);
    m_comboxFormat->addItem(tr(".ico"));
    m_comboxFormat->addItem(tr(".png"));
    m_comboxFormat->addItem(tr(".jpg"));

    m_comboxSize->setFixedSize(100, 26);
    m_comboxSize->addItem("8*8", 8);
    m_comboxSize->addItem("16*16", 16);
    m_comboxSize->addItem("24*24", 24);
    m_comboxSize->addItem("32*32", 32);
    m_comboxSize->addItem("36*36", 32);
    m_comboxSize->addItem("40*40", 40);
    m_comboxSize->addItem("48*48", 48);
    m_comboxSize->addItem("64*64", 64);
    m_comboxSize->addItem("100*100", 100);
    m_comboxSize->addItem("128*128", 128);
    m_comboxSize->addItem("256*256", 256);
    m_comboxSize->setCurrentIndex(10);
}

void MainPane::resizeEvent(QResizeEvent *event)
{

}

void MainPane::UpdatePixmap()
{
    m_labelRV->setText(QString::number(m_colorBg.red()));
    m_labelGV->setText(QString::number(m_colorBg.green()));
    m_labelBV->setText(QString::number(m_colorBg.blue()));
    m_labelAV->setText(QString::number(m_colorBg.alpha()));
    m_labelOpacityV->setText(QString::number(m_nOpacity));

    const int MAX_WIDTH = 512;

    if (m_pixOld.isNull())
    {
        m_pCanvas->SetPixmap(QPixmap());
        m_pixNew = QPixmap();
        return;
    }

    QPixmap pix(MAX_WIDTH, MAX_WIDTH);
    QRect rcBaic(0, 0, MAX_WIDTH, MAX_WIDTH);

    pix.fill(Qt::transparent);

    QPainter painter;
    painter.begin(&pix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    painter.setOpacity((double)m_nOpacity / 100.0);

    int nBorderRadius = MAX_WIDTH / 2 / 2 * m_nBorderRadius / 100;
    if (100 == m_nBorderRadius)
        nBorderRadius = MAX_WIDTH / 2;

    QPainterPath path;
    path.addRoundRect(rcBaic, nBorderRadius, nBorderRadius);
    painter.setClipPath(path);

    painter.setPen(Qt::NoPen);
    painter.setBrush(m_colorBg);
    painter.drawRect(rcBaic);

    QRect rcImg(rcBaic);
    QPixmap p = m_pixOld.scaled(rcImg.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(rcImg.marginsRemoved(QMargins(m_nPadding, m_nPadding, m_nPadding, m_nPadding)), p);

    painter.end();

    m_pCanvas->SetPixmap(pix);

    m_pixNew = pix;
}

void MainPane::CreateAllChildWnd()
{
    NEW_OBJECT(m_wTitlePane, QWidget);
    NEW_OBJECT(m_labelTitle, QLabel);
    NEW_OBJECT(m_labelLogo, QLabel);
    NEW_OBJECT(m_btnMin, QPushButton);
    NEW_OBJECT(m_btnClose, QPushButton);
    NEW_OBJECT(m_btnAbout, QPushButton);

    NEW_OBJECT(m_wLeftPane, QWidget);
    NEW_OBJECT(m_btnShape1, QPushButton);
    NEW_OBJECT(m_btnShape2, QPushButton);
    NEW_OBJECT(m_btnShape3, QPushButton);
    NEW_OBJECT(m_btnShape4, QPushButton);
    NEW_OBJECT(m_btnShape5, QPushButton);
    NEW_OBJECT(m_btnShape6, QPushButton);
    NEW_OBJECT(m_btnShape7, QPushButton);
    NEW_OBJECT(m_btnShape8, QPushButton);
    NEW_OBJECT(m_btnShape9, QPushButton);


    NEW_OBJECT(m_wContentPane, QWidget);
    NEW_OBJECT(m_pCanvas, Canvas);

    NEW_OBJECT(m_wRightPane, QWidget);
    NEW_OBJECT(m_labelPadding, QLabel);
    NEW_OBJECT(m_sliderPadding, QSlider);
    NEW_OBJECT(m_labelSeparator1, QLabel);

    NEW_OBJECT(m_labelBackgroud, QLabel);
    NEW_OBJECT(m_labelR, QLabel);
    NEW_OBJECT(m_sliderR, QSlider);
    NEW_OBJECT(m_labelRV, QLabel);
    NEW_OBJECT(m_labelG, QLabel);
    NEW_OBJECT(m_sliderG, QSlider);
    NEW_OBJECT(m_labelGV, QLabel);
    NEW_OBJECT(m_labelB, QLabel);
    NEW_OBJECT(m_sliderB, QSlider);
    NEW_OBJECT(m_labelBV, QLabel);
    NEW_OBJECT(m_labelA, QLabel);
    NEW_OBJECT(m_sliderA, QSlider);
    NEW_OBJECT(m_labelAV, QLabel);
    NEW_OBJECT(m_labelSeparator2, QLabel);
    NEW_OBJECT(m_labelOpacity, QLabel);
    NEW_OBJECT(m_sliderOpacity, QSlider);
    NEW_OBJECT(m_labelOpacityV, QLabel);

    NEW_OBJECT(m_wBottomPane, QWidget);
    NEW_OBJECT(m_btnReset, QPushButton);
    NEW_OBJECT(m_labelFormat, QLabel);
    NEW_OBJECT(m_comboxFormat, QComboBox);
    NEW_OBJECT(m_labelSize, QLabel);
    NEW_OBJECT(m_comboxSize, QComboBox);
    NEW_OBJECT(m_btnExport, QPushButton);

    NEW_OBJECT(m_pAboutdlg, About);
}

void MainPane::InitCtrl()
{
    m_wTitlePane->setProperty("form", "m_wTitlePane");
    m_wLeftPane->setProperty("form", "m_wLeftPane");
    m_wContentPane->setProperty("form", "m_wContentPane");
    m_wRightPane->setProperty("form", "m_wRightPane");
    m_wBottomPane->setProperty("form", "m_wBottomPane");

    m_wTitlePane->setFixedHeight(80);
    m_wLeftPane->setFixedSize(200, 200);
    m_wRightPane->setFixedSize(200, 200);
    m_wBottomPane->setFixedHeight(50);

    m_labelLogo->setFixedSize(50, 50);
    m_btnMin->setFixedSize(24, 24);
    m_btnClose->setFixedSize(24, 24);
    m_btnAbout->setFixedSize(24, 24);



    QImage img(":/img/img/logo.png");
    m_labelLogo->setPixmap(QPixmap::fromImage(img.scaled(m_labelLogo->size(),
                                                       Qt::IgnoreAspectRatio,
                                                       Qt::SmoothTransformation)));
    m_labelTitle->setText(tr("图标制作工具"));
    m_labelTitle->setProperty("title_label", "true");

    IconHelper::SetIcon(m_btnMin, QChar(0xe614));
    IconHelper::SetIcon(m_btnClose, QChar(0xe677));
    IconHelper::SetIcon(m_btnAbout, QChar(0xe601));
    m_btnMin->setProperty("title_btn", "true");
    m_btnClose->setProperty("title_btn", "true");
    m_btnAbout->setProperty("title_btn", "true");

    InitLeftPane();
    InitRightPane();
    InitBottomPane();

    UpdatePixmap();
}

void MainPane::InitSolts()
{
    connect(m_btnMin, SIGNAL(clicked()), this, SLOT(OnMinWindows()));
    connect(m_btnClose, SIGNAL(clicked()), this, SLOT(OnExit()));
    connect(m_btnReset, SIGNAL(clicked()), this, SLOT(OnSelectImage()));

    connect(m_pCanvas, SIGNAL(SignalSelectImage()), this, SLOT(OnSelectImage()));
    connect(m_pCanvas, SIGNAL(SignalClear()), this, SLOT(OnClear()));
    connect(m_pCanvas, &Canvas::SignalDropImageChange, [=](QString filename) {
        if(filename.isEmpty())
        {
           return;
        }
        else
        {
            QImage img2;
            if (!(img2.load(filename))) //加载图像
            {
               QMessageBox::information(this, tr("打开图像失败"), tr("打开图像失败!"));
               return;
            }

            m_pixOld = QPixmap::fromImage(img2);
            UpdatePixmap();
        }
    });

    connect(m_btnAbout, &QPushButton::clicked, [=]() {

//        m_pAboutdlg->setModal(true);
//        m_pAboutdlg->show();

//        QPoint ptBtn = m_pCanvas->mapToGlobal(m_pCanvas->pos());
//        QPoint point(ptBtn);
//        point.setX(ptBtn.x() - m_pCanvas->pos().x() + m_pCanvas->width() / 2 - m_pAboutdlg->width() / 2 - 4);
//        point.setY(ptBtn.y() - m_pCanvas->pos().y() - m_pAboutdlg->height() - 2);

//        QRect rcStart, rcEnd;
//        rcEnd = QRect(point.x(), point.y() + m_pAboutdlg->height(), m_pAboutdlg->width(), m_pAboutdlg->height());
//        rcStart = QRect(point.x(), point.y(), m_pAboutdlg->width(), m_pAboutdlg->height());

//        QPropertyAnimation *animation = new QPropertyAnimation(m_pAboutdlg, "geometry");
//        animation->setDuration(200);
//        animation->setStartValue(rcStart);
//        animation->setEndValue(rcEnd);
//        animation->start();
    });

    connect(m_btnExport, &QPushButton::clicked, [=]()
    {
        QString strFormat = m_comboxFormat->currentText();
        int size = m_comboxSize->currentData().toInt();

        QString fileName = QFileDialog::getSaveFileName(this,
                tr("保存图片"),
                "",
                (QString("保存图片(*%1)").arg(strFormat)));

        if (!fileName.isNull())
        {
            QPixmap pixTemp = m_pixNew.scaled(size, size, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QImage img = pixTemp.toImage();
            img.save(fileName, NULL, 100);
        }
    });
}

void MainPane::Relayout()
{
    QHBoxLayout *layoutHTitleTools = new QHBoxLayout();
    layoutHTitleTools->addWidget(m_btnAbout);
    layoutHTitleTools->addWidget(m_btnMin);
    layoutHTitleTools->addWidget(m_btnClose);
    layoutHTitleTools->setSpacing(0);
    layoutHTitleTools->setMargin(0);

    QVBoxLayout *layoutVTitleTools = new QVBoxLayout();
    layoutVTitleTools->addLayout(layoutHTitleTools);
    layoutVTitleTools->addStretch();
    layoutVTitleTools->setSpacing(0);
    layoutVTitleTools->setMargin(0);


    QHBoxLayout *layoutTitle = new QHBoxLayout(m_wTitlePane);
    layoutTitle->addWidget(m_labelLogo);
    layoutTitle->addWidget(m_labelTitle);
    layoutTitle->addStretch();
    layoutTitle->addLayout(layoutVTitleTools);
    layoutTitle->setSpacing(10);
    layoutTitle->setContentsMargins(10, 0, 0, 0);


    QGridLayout *layoutLeft = new QGridLayout(m_wLeftPane);
    layoutLeft->addWidget(m_btnShape1, 0, 0, 1, 1);
    layoutLeft->addWidget(m_btnShape2, 0, 1, 1, 1);
    layoutLeft->addWidget(m_btnShape3, 0, 2, 1, 1);
    layoutLeft->addWidget(m_btnShape4, 1, 0, 1, 1);
    layoutLeft->addWidget(m_btnShape5, 1, 1, 1, 1);
    layoutLeft->addWidget(m_btnShape6, 1, 2, 1, 1);
    layoutLeft->addWidget(m_btnShape7, 2, 0, 1, 1);
    layoutLeft->addWidget(m_btnShape8, 2, 1, 1, 1);
    layoutLeft->addWidget(m_btnShape9, 2, 2, 1, 1);
    layoutLeft->setSpacing(0);
    layoutLeft->setMargin(10);

    QVBoxLayout *layoutVLeft = new QVBoxLayout();
    layoutVLeft->addStretch();
    layoutVLeft->addWidget(m_wLeftPane);
    layoutVLeft->addStretch();
    layoutVLeft->setSpacing(0);
    layoutVLeft->setMargin(0);

    int nIndex = 0;
    QGridLayout *layoutRight = new QGridLayout(m_wRightPane);
    layoutRight->addWidget(m_labelPadding, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderPadding, nIndex, 1, 1, 7);

    nIndex++;
    layoutRight->addWidget(m_labelSeparator1, nIndex, 0, 1, 8);

    nIndex++;
    layoutRight->addWidget(m_labelBackgroud, nIndex, 0, 1, 8);

    nIndex++;
    layoutRight->addWidget(m_labelR, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderR, nIndex, 1, 1, 6);
    layoutRight->addWidget(m_labelRV, nIndex, 7, 1, 1);

    nIndex++;
    layoutRight->addWidget(m_labelG, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderG, nIndex, 1, 1, 6);
    layoutRight->addWidget(m_labelGV, nIndex, 7, 1, 1);

    nIndex++;
    layoutRight->addWidget(m_labelB, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderB, nIndex, 1, 1, 6);
    layoutRight->addWidget(m_labelBV, nIndex, 7, 1, 1);

    nIndex++;
    layoutRight->addWidget(m_labelA, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderA, nIndex, 1, 1, 6);
    layoutRight->addWidget(m_labelAV, nIndex, 7, 1, 1);

    nIndex++;
    layoutRight->addWidget(m_labelSeparator2, nIndex, 0, 1, 8);

    nIndex++;
    layoutRight->addWidget(m_labelOpacity, nIndex, 0, 1, 1);
    layoutRight->addWidget(m_sliderOpacity, nIndex, 1, 1, 6);
    layoutRight->addWidget(m_labelOpacityV, nIndex, 7, 1, 1);

    layoutRight->setSpacing(6);
    layoutRight->setContentsMargins(5, 10, 5, 10);

    QVBoxLayout *layoutVRight = new QVBoxLayout();
    layoutVRight->addStretch();
    layoutVRight->addWidget(m_wRightPane);
    layoutVRight->addStretch();
    layoutVRight->setSpacing(0);
    layoutVRight->setMargin(0);

    QVBoxLayout *layoutContent = new QVBoxLayout(m_wContentPane);

    layoutContent->addWidget(m_pCanvas);

    layoutContent->setSpacing(0);
    layoutContent->setMargin(15);

    QHBoxLayout *layoutCenter = new QHBoxLayout();
    layoutCenter->addLayout(layoutVLeft);
    layoutCenter->addWidget(m_wContentPane);
    layoutCenter->addLayout(layoutVRight);
    layoutCenter->setSpacing(10);
    layoutCenter->setContentsMargins(20, 0, 20, 0);


    QHBoxLayout *layoutBottom = new QHBoxLayout(m_wBottomPane);
    layoutBottom->addWidget(m_btnReset);
    layoutBottom->addStretch();
    layoutBottom->addWidget(m_labelFormat);
    layoutBottom->addWidget(m_comboxFormat);
    layoutBottom->addWidget(m_labelSize);
    layoutBottom->addWidget(m_comboxSize);
    layoutBottom->addWidget(m_btnExport);
    layoutBottom->setSpacing(10);
    layoutBottom->setMargin(15);


    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addWidget(m_wTitlePane);
    layoutMain->addLayout(layoutCenter);
    layoutMain->addWidget(m_wBottomPane);
    layoutMain->setSpacing(0);
    layoutMain->setMargin(0);
    setLayout(layoutMain);
}

QPixmap MainPane::GetPixmap( const QString &strColor, uint dwPixWidth, uint dwPixHeight, uint borderRadius )
{
    QPixmap pix(dwPixWidth, dwPixHeight);
    pix.fill(Qt::transparent);

    QPainter painter;
    painter.begin(&pix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法
    painter.setPen(QColor(strColor));
    painter.setBrush(QColor(strColor));

    painter.drawRoundedRect(pix.rect(), borderRadius, borderRadius);

    painter.end();
    return pix;
}

void MainPane::OnLeftBtnsClick()
{
    m_btnShape1->setChecked(false);
    m_btnShape2->setChecked(false);
    m_btnShape3->setChecked(false);
    m_btnShape4->setChecked(false);
    m_btnShape5->setChecked(false);
    m_btnShape6->setChecked(false);
    m_btnShape7->setChecked(false);
    m_btnShape8->setChecked(false);
    m_btnShape9->setChecked(false);

    QPushButton *btnSender = (QPushButton *)sender();
    btnSender->setChecked(true);
}

void MainPane::OnExit()
{
   emit SignalExit();
}

void MainPane::OnMinWindows()
{
    emit SignalMinWindows();
}

void MainPane::OnSelectImage()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("选择图像"),
                                                    "",
                                                    tr("Images (*.png *.bmp *.jpg *.jpeg *.ico)")); //选择路径

    if(filename.isEmpty())
    {
       return;
    }
    else
    {
        QImage img2;
        if (!(img2.load(filename))) //加载图像
        {
           QMessageBox::information(this, tr("打开图像失败"), tr("打开图像失败!"));
           return;
        }

        m_pixOld = QPixmap::fromImage(img2);
        UpdatePixmap();
    }
}

void MainPane::OnClear()
{
    m_pixOld = QPixmap();
    UpdatePixmap();
}
