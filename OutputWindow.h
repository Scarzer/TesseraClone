#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H
#include <QtGui>
#include<QtWidgets>

class OutputWindow:public QWidget
{
public:
    OutputWindow(QWidget *parent=0,Qt::WindowFlags f=0);
    void setImage(const QImage image);
    void files();
protected:
    void resizeEvent(QResizeEvent *event);
    void updatePixmap();
    QPixmap m_pixmap;
    QLabel *m_outputLabel;
    QImage Oimage;
private:


    QVector <QRgb> StackColors;
    QVector <int> redT;
    QVector <int> greenT;
    QVector <int> blueT;
    QStringList stringList;

};

#endif // OUTPUTWINDOW_H
