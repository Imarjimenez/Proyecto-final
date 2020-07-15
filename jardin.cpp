#include "jardin.h"

Jardin::Jardin()
{

}

Jardin::Jardin(int i,int w_, int h_, int x, int y)
{
    if(i==1) pixmap = new QPixmap(":/Photos/Jardin.png");
    if (i==2)pixmap = new QPixmap(":/Photos/Jardin2.png");
    w = w_;
    h = h_;
    posx = x;
    posy = y;

}

int Jardin::getW()
{
    return w;
}

int Jardin::getH()
{
    return h;
}

void Jardin::setW(int ancho)
{
    w = ancho;
}

void Jardin::setH(int altura)
{
    h = altura;
}

int Jardin::getPosx()
{
    return posx;
}

void Jardin::setPosx(int px)
{
    posx=px;
}

int Jardin::getPosy()
{
    return posy;
}

void Jardin::setPosy(int py)
{
    posy = py;
}

QRectF Jardin::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void Jardin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}
