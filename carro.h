

#ifndef CARRO_H
#define CARRO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPixmap>



#include <QRectF>

class Carro : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Carro(QObject * parent = nullptr);


    QPixmap *pixmap;


    int posx, posy;
    int velocidad=5;
    float ancho;
    float alto;
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


};

#endif // CUERPO_H
