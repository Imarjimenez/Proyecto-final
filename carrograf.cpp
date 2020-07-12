
#include "carrograf.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include <QPainter>
#include <QImage>



carrograf::carrograf(int x) : escala(1) //Se encuentran los valores iniciales de cada esfera de forma aleatoria.
{
    player = x;
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = 32;
    posy = 150;
    r = 20;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;
    esf = new Carro(posx,posy,velx,vely,mass,r,K,e); //Se le asignan a una esfera sus valores.
}

carrograf::~carrograf()
{
    delete esf;
}

QRectF carrograf::boundingRect() const
{
        return QRectF(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio());
}

void carrograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(player == 1){
        painter->drawPixmap(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio(),QPixmap(":/Photos/carro.png"));        //asigna el color
        painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
    }
    if(player == 2){
        painter->drawPixmap(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio(),QPixmap(":/player2"));        //asigna el color
        painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
    }
}

void carrograf::erase(QPainter *painter){
    painter->eraseRect(-1*escala*esf->get_Radio(),-1*escala*esf->get_Radio(),2*escala*esf->get_Radio(),2*escala*esf->get_Radio());
}

void carrograf::setEscala(float s)
{
    escala=s;
}

void carrograf::actualizar(float v_lim)
{
    esf->actualizar();
    setPos(esf->get_posX(),(v_lim-esf->get_posY()));
}

Carro *carrograf::getEsf()
{
    return esf;
}
