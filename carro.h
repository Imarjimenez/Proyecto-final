#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QObject>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <QKeyEvent>
#include <QMainWindow>
#include <QDebug>

class Carro: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Carro(QObject * parent = nullptr);
    QPixmap *pixmap;



    float Velx,Vely,VV,aX,aY,dt,angulo;
    int posx, posy;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void actualizar();



};

#endif // CARRO_H
