#ifndef VELOCIMETRO_H
#define VELOCIMETRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Velocimetro: public QGraphicsItem
{
    int w,h;
    int posx, posy;

    QPixmap *pixmap;


public:
    Velocimetro(int i,int w_, int h_, int x, int y);
    Velocimetro();
    int getW();
    void setW(int ancho);
    int getH();
    void setH(int altura);
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void rotar();
};

#endif // VELOCIMETRO_H
