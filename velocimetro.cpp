#include "velocimetro.h"

Velocimetro::Velocimetro()
{

}

Velocimetro::Velocimetro(int i,int w_, int h_, int x, int y)
{
    if(i==1) pixmap = new QPixmap(":/Photos/velocimetro.png");
    if (i==2)pixmap = new QPixmap(":/Photos/aguja.png");

    w = w_;
    h = h_;
    posx = x;
    posy = y;

}

int Velocimetro::getW()
{
    return w;
}

int Velocimetro::getH()
{
    return h;
}

void Velocimetro::setW(int ancho)
{
    w = ancho;
}

void Velocimetro::setH(int altura)
{
    h = altura;
}

int Velocimetro::getPosx()
{
    return posx;
}

void Velocimetro::setPosx(int px)
{
    posx=px;
}

int Velocimetro::getPosy()
{
    return posy;
}

void Velocimetro::setPosy(int py)
{
    posy = py;
}

QRectF Velocimetro::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void Velocimetro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}
