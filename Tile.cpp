#include "Tile.h"
#include "QDebug"

Tile::Tile(){

}

Tile::Tile(const Tile& otherTile ){
    _tileName = otherTile._tileName;
    _width = otherTile._width;
    _height = otherTile._height;
    _red = otherTile._red;
    _blue = otherTile._blue;
    _green = otherTile._green;
    _avgValue = otherTile._avgValue;
    _image = otherTile._image;

}

Tile::Tile (QString fileName){
    

    if(_image.load(fileName)){
    _tileName =   fileName ;
    _width    =   _image.width();
    _height   =   _image.height();

    int tR = 0, tG = 0, tB = 0;
    QRgb currPixel;

    for(int i = 0; i < _height; i++){
        for(int j = 0; j < _width; j++){
            // Calculating the average for the whole image
            currPixel = _image.pixel(i,j);
            tR += qRed(currPixel);
            tG += qGreen(currPixel);
            tB += qBlue(currPixel);

        }
    }
    int area = _width * _height;
    
    _red    = tR * (1.0/area);
    _green  = tG * (1.0/area);
    _blue   = tB * (1.0/area);

    _avgValue = qRgb(_red, _green, _blue);
}

    else qDebug() << fileName << " is not a file";
    }




QRgb Tile::colorKey(){
    return _avgValue;
}

QPixmap Tile::getScaled(int width, int height){
    QImage temp = _image.scaled(width, height);
    QPixmap returnTile;
    
    if(returnTile.convertFromImage(_image)){
        return returnTile;
    }
    else{
        qDebug() << "There was an error!";
        qDebug() << "My name is " << _tileName << " and my avg is " << _avgValue;
        return returnTile;
    }
}
    
QString Tile::getName(){
    return Tile::_tileName.section('/', 6, 7);
}
