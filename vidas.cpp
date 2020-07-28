#include "vidas.h"



Vidas::Vidas(int x,int y)
{


    pixmap = new QPixmap(":/Photos/vidas.png");



    posx=x;
    posy=y;



    //dimensiones de c/U de las imagenes
    ancho =20;
    alto  = 20;



}
int Vidas::getPosx()
{
    return posx;
}

void Vidas::setPosx(int px)
{
    posx=px;
}

int Vidas::getPosy()
{
    return posy;
}

void Vidas::setPosy(int py)
{
    posy = py;
}

QRectF Vidas::boundingRect() const
{
    return QRectF(posx,posy,ancho,alto);
}

void Vidas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);



}







