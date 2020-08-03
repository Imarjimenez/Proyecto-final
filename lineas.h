#ifndef LINEAS_H
#define LINEAS_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <carro.h>


class Lineas: public Carro
{
    int w,h;
    int posx, posy;

public:
    Lineas();
    Lineas(int w_, int h_, int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // LINEAS_H
