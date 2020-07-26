#include "volante.h"



Volante::Volante(int x,int y)
{


    pixmap = new QPixmap(":/Photos/volante.png");
    //pixmap->scaled(131,31,Qt::KeepAspectRatio);


    posx=x;
    posy=y;



    //dimensiones de c/U de las imagenes
    ancho =150;
    alto  = 124;







}
int Volante::getPosx()
{
    return posx;
}

void Volante::setPosx(int px)
{
    posx=px;
}

int Volante::getPosy()
{
    return posy;
}

void Volante::setPosy(int py)
{
    posy = py;
}

QRectF Volante::boundingRect() const
{
    return QRectF(posx,posy,ancho,alto);
}

void Volante::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);



}
