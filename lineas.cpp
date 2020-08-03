#include "lineas.h"

Lineas::Lineas()
{

}

Lineas::Lineas(int w_, int h_, int x, int y)
{
    w = w_;
    h = h_;
    posx = x;
    posy = y;

}


QRectF Lineas::boundingRect() const
{
    return QRectF(-posx,-posy,w,h);
}

void Lineas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
}
