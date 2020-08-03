#include "volante.h"



Volante::Volante(int x,int y)
{


    pixmap = new QPixmap(":/Photos/volante.png");
    //pixmap->scaled(131,31,Qt::KeepAspectRatio);


    posx=x;
    posy=y;
    setPos(x,y);

    angulo=0;

    //dimensiones de c/U de las imagenes
    ancho =150;
    alto  = 124;







}
int Volante::getPosx()
{
    return posx;
}

void Volante::setPosx(int px)
{
    posx=px;
}

int Volante::getPosy()
{
    return posy;
}

void Volante::setPosy(int py)
{
    posy = py;
}

QRectF Volante::boundingRect() const
{
    return QRectF(-75,-62,ancho,alto);
}

void Volante::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-75,-62,*pixmap);



}

void Volante::rotar_right()
{
    if(angulo<=90){
    angulo+=30;
    setRotation(angulo);}


}
void Volante::rotar_left(){
    if(angulo>=-90){
    angulo-=30;}

    setRotation(angulo);

}

void Volante::soltar()
{
    angulo=0;
    setRotation(angulo);
}
