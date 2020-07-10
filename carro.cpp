#include "carro.h"



Carro::Carro(QObject *parent) : QObject(parent)
{

    pixmap = new QPixmap(":/Photos/carro.png");
    posx=100;
    posy=300;
    Velx=5;
    Vely=5;
    aX=0;
    aY=0;
    VV=0;
    dt=0.1;
}

QRectF Carro::boundingRect() const
{
    return QRectF(posx,posy,100,117);
}

void Carro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(posx,posy,*pixmap);
}



void Carro::actualizar()
{
    VV=pow(((Velx*Velx)+(Vely*Vely)),(1/2));
    angulo= atan2(Vely,Velx);

    aX=4;
    aY=4;
    posx= posx + ((Velx*(dt*dt))) + (((aX*(dt*dt)))/2);
    posy= posy + ((Vely*(dt*dt))) + (((aY*(dt*dt)))/2);
    Velx= Velx + aX*dt;
    Vely= Vely + aY*dt;
}


























