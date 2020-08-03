#include "jardin.h"

Jardin::Jardin()
{

}

Jardin::Jardin(int i,int w_, int h_, int x, int y)
{
    if(i==1) pixmap = new QPixmap(":/Photos/Jardin.png");
    if (i==2)pixmap = new QPixmap(":/Photos/Jardin2.png");
    if (i==3)pixmap = new QPixmap(":/Photos/carro1.png");
    if (i==4)pixmap = new QPixmap(":/Photos/carro2.png");
    if (i==5)pixmap = new QPixmap(":/Photos/carro3.png");
    if (i==6)pixmap = new QPixmap(":/Photos/carro4.png");    
    if (i==7)pixmap = new QPixmap(":/Photos/carreras.png");
    w = w_;
    h = h_;
    posx = x;
    posy = y;

}

QRectF Jardin::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void Jardin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}
