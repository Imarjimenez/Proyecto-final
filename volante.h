
#ifndef VOLANTE_H
#define VOLANTE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPixmap>

#include <QRectF>

class Volante : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int posx, posy;

public:
    Volante(int x,int y);
    QPixmap *pixmap;

    float ancho;
    float alto;
    int angulo;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void rotar_right();
    void rotar_left();
    void soltar();

};

#endif // VOLANTE_H
