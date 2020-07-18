#include "carro.h"



Carro::Carro(QObject *parent) : QObject(parent)
{

    ancho=100;
    alto=117;
    pixmap = new QPixmap(":/Photos/carro.png");


    posx=100;
    posy=100;




}


QRectF Carro::boundingRect() const
{
    return QRectF(posx,posy,ancho,alto);
}

void Carro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}

void Carro::Up(float vel)
{
    if(vel<=20) vel+=5;
    posy -= vel;
    setPos(posx,posy);


}

void Carro::Down(float vel)
{
    if(vel> 20) vel+=5;
    posy += vel;
    setPos(posx,posy);
}

void Carro::Left()
{

    angulo-=15;
    setTransformOriginPoint(120,120);

    setRotation(angulo);


}

void Carro::Rigth()
{

    angulo+=15;
    setTransformOriginPoint(120,120);

    setRotation(angulo);



}



















