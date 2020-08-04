

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
    float vel;
    float ancho;
    float alto;
    float angulo;
    float des;
    float acc;
    float maxspeed;
    float turnspeed;
    bool up;
    bool down;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    int getVel();
    void setVel(int v);
    float getAngulo();
    void setAngulo(int a);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Up();
    void Down();
    void noUp();
    void noDown();
    void Left();
    void Rigth();
    void perder();
public slots:
    void frenar();
    void tiempo();
private:
    QTimer *mover;
    QTimer *check_break;


};




#endif // CARRO_H
