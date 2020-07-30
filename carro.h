

#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <QtGui>
#include "volante.h"
#include "velocimetro.h"




#include <QRectF>

class Carro : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Carro(QObject * parent = nullptr);


    QPixmap *pixmap;

    float posx, posy;
    float vel;
    float ancho;
    float alto;
    int angulo;
    float t;
    float dx;
    float dy;
    float hipotenusa;
    float alp;



    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Up();
    void Down();
    void Left();
    void Rigth();
public slots:

    void tiempo();
private:
    QTimer *mover;


};




#endif // CARRO_H
