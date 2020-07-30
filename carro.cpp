#include "carro.h"



Carro::Carro(QObject *parent) : QObject(parent)
{

    ancho=100;
    alto=117;
    pixmap = new QPixmap(":/Photos/carro.png");
    posx=400;
    posy=540;
    setPos(posx,posy);

    vel=0;
    dx=0;
    dy=0;
    hipotenusa=sqrt(ancho*ancho+alto*alto);
    alp=atan(ancho/alto);
    angulo=0;

    QTimer *mover= new QTimer(this);
    connect(mover,SIGNAL(timeout()),this,SLOT(tiempo()));
    mover->start(20);




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
    if(vel<=5) vel++;
//    posy -= vel;
//    setPos(posx,posy);


}

void Carro::Down()
{
    if(vel>-5) vel--;
//    posy += vel;
//    setPos(posx,posy);
}

void Carro::Left()
{

//    angulo-=15;


//    setRotation(angulo);
//    posx+=vel;
//    dx=hipotenusa*sin(angulo*3.141592/180+3.141592-alp);
//    dy= hipotenusa*cos(angulo*3.141592/180+3.141592-alp);
    angulo--;
//    posx+= sin(angulo)*vel;
//    posy-= cos(angulo)*vel;
    setTransformOriginPoint(50,58);
      this->setRotation(angulo);
//    setPos(posx,posy);


}

void Carro::Rigth()
{


//    dx=hipotenusa*sin(angulo*3.141592/180+3.141592-alp);
//    dy= hipotenusa*cos(angulo*3.141592/180+3.141592-alp);
    angulo ++;
//    posx+= sin(angulo)*vel;
    setTransformOriginPoint(50,58);
//    posy-= cos(angulo)*vel;
    setRotation(angulo);



}

void Carro::tiempo()
{

    posy-= cos(angulo*3.141592/180)*vel;
    if(vel>=0){
        posx+= sin(angulo*3.141592/180)*vel;
    }
    else{
        posx-=sin(angulo*3.141592/180)*vel;
    }
    setPos(posx,posy);
    t++;


}



















