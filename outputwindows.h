#ifndef OUTPUTWINDOWS_H
#define OUTPUTWINDOWS_H

#include <QtWidgets>
#include "Tile.h"

class OutputWindows : public QWidget
{
    Q_OBJECT
public:
    explicit OutputWindows(QWidget *parent = 0);
    void    applyImage(QImage inImage, QMap<QRgb, Tile>);

private:
    void    resizeEvent(QResizeEvent *event);
    void    _updatePixmap();
    QRgb    _findTile (QRgb pixelColor);


    int                 m_numCached;
    int                 m_numDirect;
    int                 m_tileX;
    int                 m_tileY;
    int                 m_scaleFactor;
    QPixmap             m_pixmap;
    QLabel              *m_outLabel;
    QVBoxLayout         *m_pixBox;
    QMap <QRgb, Tile>   m_availableTiles;
    QHash<QRgb, QRgb>   m_cachedPixels;
};

#endif // OUTPUTWINDOWS_H
