#ifndef MAINPANE_H
#define MAINPANE_H

#include <QWidget>

#include "global.h"


class Canvas;
class About;
class MainPane : public QWidget
{
    Q_OBJECT
public:
    explicit MainPane(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);

private:
    GLOBAL_FUNC

    void InitLeftPane();
    void InitRightPane();
    void InitBottomPane();

    void resizeEvent(QResizeEvent *event);


    void UpdatePixmap();

    QPixmap GetPixmap( const QString &strColor, uint dwPixWidth, uint dwPixHeight, uint borderRadius );

private slots:
    void OnLeftBtnsClick();

    void OnExit();
    void OnMinWindows();
    void OnSelectImage();
    void OnClear();

signals:
    void SignalExit();
    void SignalMinWindows();

private:
    QWidget *m_wTitlePane;
    QLabel *m_labelLogo;
    QLabel *m_labelTitle;
    QPushButton *m_btnMin;
    QPushButton *m_btnClose;
    QPushButton *m_btnAbout;


    QWidget *m_wLeftPane;
    QPushButton *m_btnShape1;
    QPushButton *m_btnShape2;
    QPushButton *m_btnShape3;
    QPushButton *m_btnShape4;
    QPushButton *m_btnShape5;
    QPushButton *m_btnShape6;
    QPushButton *m_btnShape7;
    QPushButton *m_btnShape8;
    QPushButton *m_btnShape9;

    QWidget *m_wContentPane;
    Canvas *m_pCanvas;

    QWidget *m_wRightPane;
    QLabel *m_labelPadding;
    QSlider *m_sliderPadding;
    QLabel *m_labelSeparator1;
    QLabel *m_labelBackgroud;
    QLabel *m_labelR;
    QSlider *m_sliderR;
    QLabel *m_labelRV;
    QLabel *m_labelG;
    QSlider *m_sliderG;
    QLabel *m_labelGV;
    QLabel *m_labelB;
    QSlider *m_sliderB;
    QLabel *m_labelBV;
    QLabel *m_labelA;
    QSlider *m_sliderA;
    QLabel *m_labelAV;
    QLabel *m_labelSeparator2;
    QLabel *m_labelOpacity;
    QSlider *m_sliderOpacity;
    QLabel *m_labelOpacityV;

    QWidget *m_wBottomPane;
    QPushButton *m_btnReset;
    QLabel *m_labelFormat;
    QComboBox *m_comboxFormat;
    QLabel *m_labelSize;
    QComboBox *m_comboxSize;
    QPushButton *m_btnExport;

    About *m_pAboutdlg;

    QPixmap m_pixOld;
    QPixmap m_pixNew;
    uint m_nBorderRadius;
    uint m_nPadding;
    QColor m_colorBg;
    uint m_nOpacity;
};

#endif // MAINPANE_H
