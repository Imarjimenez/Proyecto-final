

#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <math.h>
#include <QtGui>




#include <QRectF>

class Carro : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Carro(QObject * parent = nullptr);


    QPixmap *pixmap;

    float posx, posy;
    float ancho;
    float alto;
    int angulo=0;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Up(float velocidad);
    void Down(float velocidad);
    void Left();
    void Rigth();
    Carro *carro;


};




#endif // CARRO_H
