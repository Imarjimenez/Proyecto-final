#ifndef VELOCIMETRO_H
#define VELOCIMETRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>



class Velocimetro: public QGraphicsItem
{
    int w,h;
    int posx, posy;
    float angulo;

    QPixmap *pixmap;


public:
    Velocimetro(int i,int w_, int h_, int x, int y);
    Velocimetro();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void acelerar();
    void retroceder();
    void mitad();
};

#endif // VELOCIMETRO_H
