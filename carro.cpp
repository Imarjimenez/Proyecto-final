#include "carro.h"

Carro::Carro(QObject *parent) : QObject(parent)
{
    ancho=100;
    alto=117;
    pixmap = new QPixmap(":/Photos/carro.png");
    posx=400;
    posy=510;
    acc=0.2;
    des=0.2;
    maxspeed=5;
    turnspeed=0.08;
    up=0; down=0;
    setPos(posx,posy);
    vel=0;
    angulo=0;

    QTimer *mover= new QTimer(this);
    connect(mover,SIGNAL(timeout()),this,SLOT(tiempo()));
    mover->start(20);
    QTimer *check_break = new QTimer(this);
    connect(check_break,SIGNAL(timeout()),this,SLOT(frenar()));
    check_break->start(20);
}

QRectF Carro::boundingRect() const
{
    return QRectF(-50,-58,100,117);
}

void Carro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-50,-58,*pixmap);
}

void Carro::Up()
{
    up = 1;
    if(vel<=maxspeed){
        if (vel<0) vel+=des;
        else vel+=acc;
    }
}

void Carro::Down()
{
    down=1;
    if(vel>-maxspeed){
        if (vel>0) vel-=des;
        else vel-=acc;
    }
}

void Carro::Left()
{
    if(vel!=0)angulo-=turnspeed*vel/maxspeed;
}

void Carro::Rigth()
{
    if(vel!=0)angulo+=turnspeed*vel/maxspeed;
}

void Carro::noUp()
{
    up = 0;
}

void Carro::noDown()
{
    down=0;
}
void Carro::perder()
{
    posx=400;
    posy=510;
    vel=0;
    setPos(posx,posy);
}

void Carro::frenar()
{
    if (up==0 && down==0){
        if(vel-des>0)vel-=des;
        else if (vel+des<0)vel+=des;
        else vel=0;
    }
}

void Carro::tiempo()
{
    posx+= sin(angulo)*vel;
    posy-= cos(angulo)*vel;
    setPos(posx,posy);
    this->setRotation(angulo*180/3.141592);
}

int Carro::getPosx()
{
    return posx;
}

void Carro::setPosx(int px)
{
    posx=px;
}

int Carro::getPosy()
{
    return posy;
}

void Carro::setPosy(int py)
{
    posy = py;
}

int Carro::getVel()
{
    return vel;
}

void Carro::setVel(int v)
{
    vel = v;
}
















