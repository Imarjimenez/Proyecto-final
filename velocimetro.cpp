#include "velocimetro.h"

Velocimetro::Velocimetro()
{

}

Velocimetro::Velocimetro(int i,int w_, int h_, int x, int y)
{
    if(i==1) pixmap = new QPixmap(":/Photos/velocimetro.png");
    if (i==2)pixmap = new QPixmap(":/Photos/aguja.png");
    angulo=-90;
    w = w_;
    h = h_;
    posx = x;
    posy = y;
    setPos(x,y);
    if(i==2){
    setRotation(angulo);}

}


QRectF Velocimetro::boundingRect() const
{
    return QRectF(-100,-65,w,h);
}

void Velocimetro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-100,-65,*pixmap);
}

void Velocimetro::acelerar()
{

    angulo=0;
    setRotation(angulo);
}

void Velocimetro::retroceder()
{
    angulo=-180;
    setRotation(angulo);
}

void Velocimetro::mitad()
{
    angulo=-90;
    setRotation(angulo);
}
