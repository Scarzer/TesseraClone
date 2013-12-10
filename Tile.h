#ifndef TILE_H
#define TILE_H

#include <QImage>

class Tile{ 

public:
    Tile( QString fileName );
    QRgb colorKey();
    QImage getScaled(int width, int height);

    int     _red;
    int     _green;
    int     _blue;

protected:
    
        


private:

    int     _width;
    int     _height;
    QRgb  _avgValue;
    QImage  _image;

};


#endif
