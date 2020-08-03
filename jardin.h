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
    Jardin(int i,int w_, int h_, int x, int y);
    Jardin();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // JARDIN_H
