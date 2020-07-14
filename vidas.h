

#ifndef VIDAS_H
#define VIDAS_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsItem>

#include <QPixmap>
#include <QPainter>


#include <QRectF>

class Vidas : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx, posy;

public:
    Vidas(int x,int y);

    QPixmap *pixmap;



    float ancho;
    float alto;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};
#endif // VIDAS_H
