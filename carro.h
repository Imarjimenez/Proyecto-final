

#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPixmap>
#include <QTimer>



#include <QRectF>

class Carro : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Carro(QObject * parent = nullptr);


    QPixmap *pixmap;


    float ancho;
    float alto;
    float posx;
    float posy;
    float velx;
    float vely;
    float angulo;
    float aX;
    float aY;
    float VV;
    float dt;
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    float getVelx();
    void setVelx(int vx);
    float
    getVely();
    void setVely(int vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Up();
    void Down();
    void Left();
    void Rigth();
public slots:
    void mover();

};

#endif // CUERPO_H
