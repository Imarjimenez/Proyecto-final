#include "carro.h"



Carro::Carro(QObject *parent) : QObject(parent)
{


    pixmap = new QPixmap(":/Photos/carro.png");



    //dimensiones de c/U de las imagenes
    ancho =100;
    alto  = 117;

    posx=100;
    posy=300;




}



QRectF Carro::boundingRect() const
{
    return QRectF(posx,posy,ancho,alto);
}

void Carro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}

void Carro::Up()
{
    posy -= 2*velocidad;
    setPos(posx,posy);
}

void Carro::Down()
{
    posy+=2*velocidad;
    setPos(posx,posy);
}

void Carro::Left()
{
    posx -= 2*velocidad;
    setPos(posx,posy);
}

void Carro::Rigth()
{
    posx+=2*velocidad;
    setPos(posx,posy);
}
















