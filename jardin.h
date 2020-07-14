#ifndef JARDIN_H
#define JARDIN_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class Jardin: public QGraphicsItem
{
    int w,h;
    int posx, posy;
    QPixmap *pixmap;

public:
    Jardin();
    Jardin(int w_, int h_, int x, int y);
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

};

#endif // JARDIN_H
