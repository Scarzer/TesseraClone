#include "outputwindows.h"

OutputWindows::OutputWindows(QWidget *parent) :
    QWidget(parent)
{

    m_pixBox = new QVBoxLayout;
    m_outLabel = new QLabel("No Out Image");
    m_outLabel->setAlignment(Qt::AlignCenter);
    m_pixBox->addWidget(m_outLabel);
    setLayout(m_pixBox);

    m_tileX = 15;
    m_tileY = 15;
    m_numCached = 0;
    m_numDirect = 0;
    m_scaleFactor = 2;



}

void OutputWindows::applyImage(QImage inImage, QMap<QRgb, Tile> inTiles){
    m_availableTiles = inTiles;
    inImage = inImage.scaled(inImage.width()/2, inImage.height()/2);

    int imgHeight = inImage.height();
    int imgWidth  = inImage.width();
    int sWidth    = imgWidth*m_tileX;
    int sHeight   = imgHeight*m_tileY;

    QImage tempOut(sWidth, sHeight , QImage::Format_RGB32);
    tempOut.fill(5);
    qDebug() << "The Out is: " << tempOut.isNull();
    QPainter placedTiles;

    placedTiles.begin(&tempOut);
    int painterX = 0;
    int painterY = 0;
    qDebug() << "Image Height: " << imgHeight;
    qDebug() << "Image Width: " << imgWidth;
    qDebug() << "Tiles: " << m_availableTiles.count();
    qDebug() << "Pixel(0,0): " << inImage.pixel(0,0);
    qDebug() << "Find Output: " << _findTile(inImage.pixel(0,0));
    QTime timeToMake;
    timeToMake.start();
    for(int i = 0; i < imgHeight; i++){
        for( int j = 0; j < imgWidth; j++){
            QPixmap toBePlaced;

            QRgb transPixel = inImage.pixel(j, i);
            QRgb uncoveredPixel = _findTile(transPixel);

            toBePlaced = inTiles[uncoveredPixel].getScaled(m_tileX, m_tileY);
            placedTiles.drawImage(painterX, painterY, toBePlaced.toImage());
            painterX += m_tileX;
            //exit(2);
        }
        painterX = 0;
        painterY += m_tileY;
    }

    placedTiles.end();
    qDebug() << "Number of cached Pixels: " << m_numCached;
    m_pixmap.convertFromImage(tempOut);
    qDebug() << "Some info: " << m_pixmap.isNull();

    m_outLabel->setPixmap(m_pixmap);
    _updatePixmap();

    bool save = tempOut.save("/Users/scarzer/createdMosaic.jpg");
    qDebug() << "save: " << save;
    qDebug() << "Time Elapsed: " << timeToMake.elapsed();
}


QRgb OutputWindows::_findTile(QRgb pixelColor){
    //If we've analyized this already, return it!
    if(m_cachedPixels.contains(pixelColor)){
        m_numCached++;
        return m_cachedPixels[pixelColor];
    }

    // If we have a direct match, return it!
    if(m_availableTiles.contains(pixelColor)){
        m_numDirect++;
        return pixelColor;
    }

    //If nothing else, we must evaluate!
    QMapIterator<QRgb, Tile> i(m_availableTiles);

    int tR = qRed(i.key());
    int tG = qGreen(i.key());
    int tB = qBlue(i.key());

    // Pixel Colors
    int pR = qRed(pixelColor);
    int pG = qGreen(pixelColor);
    int pB = qBlue(pixelColor);

    double baseLine = sqrt(pow(pR-tR,2) + pow(pG-tG,2) + pow(pB-tB, 2));
    //qDebug() << "Baseline Value: " << baseLine;
    QRgb   tempPix = pixelColor;

    // Look for the pixel that is the most similar!;
    while(i.hasNext()){
        i.next();
        // Tile Colors
        int tR = qRed(i.key());
        int tG = qGreen(i.key());
        int tB = qBlue(i.key());

        double sqrDiff = sqrt(pow(pR-tR,2) + pow(pG-tG,2) + pow(pB-tB, 2));
        if(baseLine > sqrDiff){
            tempPix = i.key();
            baseLine = sqrDiff;
        }
        //qDebug() << "The Match is: " << tempPix;
    }

    // Cache the Pixel, and return the QRbg Key for the tile.
    m_cachedPixels.insert(pixelColor, tempPix);
    return tempPix;
}

void OutputWindows::_updatePixmap(){
    if(m_pixmap.isNull()){
        qDebug() << "Derp" ;
        return;
    }

    int width = m_outLabel->width();
    int height = m_outLabel->height();

    if (width < height) m_outLabel-> setPixmap(m_pixmap.scaledToWidth(width));
    else m_outLabel->setPixmap(m_pixmap.scaledToHeight(height));

}

void OutputWindows::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);
    qDebug() << "Updating Size";
    _updatePixmap();
}
