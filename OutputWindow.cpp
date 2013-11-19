#include "OutputWindow.h"
#include "mainwindow.h"
#include <iostream>
using namespace std ;


OutputWindow::OutputWindow(QWidget *parent, Qt::WindowFlags f)
    :QWidget(parent, f)
{
    m_outputLabel= new QLabel("No Output");
    m_outputLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *vbox =new QVBoxLayout;

    vbox->addWidget(m_outputLabel);
    files();
    setLayout(vbox);
}

void OutputWindow::files(){

    // QFile textFile(":/TileImages/text.txt");
    QFile textFile("TileImages/text.txt");
    if (textFile.open(QIODevice::ReadOnly))
    {
       QTextStream textStream(&textFile);
       while (!textStream.atEnd())
       {
          stringList.append(textStream.readLine());
       }

   }
    textFile.close();

    for (int i=0;i<stringList.size();i++)
    {
                 // stringList[i].prepend(":/TileImages/");
                 stringList[i].prepend("TileImages/");
         cout<< stringList[i].toStdString()<<endl;
    }

//Read all files and get RGB values, RGB values are stored in QVectors


    for (int j=0;j<stringList.size();j++)
    {
         QImage tImage;
         tImage.load(stringList[j]);
         if (!tImage.isNull())
         {

              QImage imageScaled=tImage.scaled(1,1, Qt::IgnoreAspectRatio,
                                              Qt::SmoothTransformation);

              StackColors.push_back(imageScaled.pixel(0,0));
         }
    }
  //  cout<<StackColors[stringList.size()-1]<<endl;
    cout<<stringList.size()<<endl;
    for (int j=0;j<stringList.size();j++){
        QColor color=StackColors[j];
        redT.push_back(color.red());
        greenT.push_back(color.green());
        blueT.push_back(color.blue());
    }


}


void OutputWindow::setImage(const QImage image)
{
    int mosaic=40;
    int x=qFloor(8*mosaic/3);
    int y=qFloor(x*image.height()/image.width());

     Oimage=image.scaled(x,y,Qt::IgnoreAspectRatio,
              Qt::SmoothTransformation);

    int matrix[Oimage.height()][Oimage.width()];

    for ( int row =0; row <Oimage.height();row++)
    {
       for ( int col =0; col<Oimage.width(); col++)
      {

           QColor color_image;
           color_image=Oimage.pixel(col,row);
           int red;
           int green;
           int blue;
            red=color_image.red();
            green=color_image.green();
            blue=color_image.blue();
            int d[stringList.size()];
             int value,index=0;
                         for (int tile=0;tile<redT.size();tile++)
                      {
                            d[tile]=((red-redT[tile])*(red-redT[tile]))+
                             ((green-greenT[tile])*(green-greenT[tile]))+
                             ((blue-blueT[tile])*(blue-blueT[tile]));

                        }
                         value=d[0];
                         for (int n=1;n<stringList.size();n++)
                         {
                             if (value>d[n])
                             {
                                 value=d[n];
                                 index=n;
                             }
                         }
                         matrix[row][col]=index;//assign the index, which tile matches



           }
    }
    //width and height = the size of the tile
   int width=90;

   int height=90;
QImage output(width*x,height*y,QImage::Format_RGB32);

    int r=0;int c=0;
                 for ( int row =0; row <output.height();row+=height)
                 {


                    for ( int col =0; col<output.width(); col+=width)
                   {
                        QImage tImage;
                        tImage.load(stringList[matrix[r][c]]);

                        QImage tiles;
                         tiles=tImage.scaled(width,height, Qt::IgnoreAspectRatio,
                                                        Qt::SmoothTransformation);
                         QPainter oTile;
                         oTile.begin(&output);
                         oTile.drawImage(col,row,tiles);
                         oTile.end();
                    c++;

                    }
                    c=0;
                    r++;


                 }


          //scaling down final image is less than 4000 px
               QImage out=output.scaled(x*30,y*30, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    m_pixmap=QPixmap::fromImage(out);

   updatePixmap();
}
void OutputWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updatePixmap();
}

void OutputWindow::updatePixmap()
{

    if (m_pixmap.isNull())
        return;

    int w=m_outputLabel->width();
    int h=m_outputLabel->height();
            if (w<h)
            m_outputLabel->setPixmap(m_pixmap.scaledToWidth(w));
             else
                m_outputLabel->setPixmap(m_pixmap.scaledToHeight(h));
}
