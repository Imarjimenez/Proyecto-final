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
    mover();
    setPos(posx,posy);
}

void Carro::Down()
{
    mover();
    setPos(posx,posy);
}

void Carro::Left()
{
    mover();
    setPos(posx,posy);
}

void Carro::Rigth()
{

    mover();
    setPos(posx,posy);
}

void Carro::mover()
{
    VV = pow(((velx*velx)+(vely*vely)),(1/2));
    angulo = atan2(vely, velx);

    aX =4;
    aY =4;
    posx = posx + ((velx*(dt*dt))) + (((aX*(dt*dt)))/2);
    posy = posy + ((vely*(dt*dt))) + (((aY*(dt*dt)))/2);
    velx = velx + aX*dt;
    vely = vely + aY*dt;
}

//#include "cuerpos.h"
//#include <math.h>
//#include <cmath>

//cuerpos::cuerpos(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_) //Asigna valores iniciales a cada esfera.
//{
//    posX = posX_;
//    posY = posY_;
//    masa = masa_;
//    radio = radio_;
//    velX = velX_;
//    velY = velY_;
//    aX = 0;
//    aY = 0;
//    G = 10;
//    K = K_;
//    e = e_;
//    VV = 0;
//    dt = 0.1;

//}
//cuerpos::~cuerpos()
//{

//}
//void cuerpos::actualizar(){ //Actualiza cada valor para que la posicion se modifique;
//    VV = pow(((velX*velX)+(velY*velY)),(1/2));
//    angulo = atan2(velY, velX);
//    if (velX >= 0){
//    aX = (-((K*(VV*VV)*(radio*radio))/masa)*cos(angulo))-1;
//    }
//    if(velX < 0){
//        aX = (-((K*(VV*VV)*(radio*radio))/masa)*cos(angulo))+1;
//    }
//    aY = (-((K*(VV*VV)*(radio*radio))/masa)*sin(angulo))-G;
//    posX = posX + ((velX*(dt*dt))) + (((aX*(dt*dt)))/2);
//    posY = posY + ((velY*(dt*dt))) + (((aY*(dt*dt)))/2);
//    velX = velX + aX*dt;
//    velY = velY + aY*dt;

//}

//float cuerpos::get_posX(){
//    return posX;
//}

//float cuerpos::get_posY(){
//    return posY;
//}

//float cuerpos::get_velx(){
//    return velX;
//}

//float Carro::getVelx(){
//    return velY;
//}


//void cuerpos::set_vel(float velx, float vely, float px, float py){ //Obtiene nuevas velocidades.
//    velX = velx;
//    velY = vely;
//    posX = px;
//    posY = py;
//}















