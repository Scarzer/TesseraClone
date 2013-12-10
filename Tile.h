#ifndef TILE_H
#define TILE_H

#include <QImage>
#include <QPixmap>

class Tile{ 

public:
    Tile( QString fileName );
    QRgb colorKey();
    QPixmap getScaled(int width, int height);
    QString getName();


    protected:
    
        


private:

    int     _width;
    int     _height;
    int     _red;
    int     _green;
    int     _blue;

    QString _tileName;
    QRgb    _avgValue;
    QImage  _image;

};


#endif
