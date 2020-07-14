#include "tiempo.h"
#include "mainwindow.h"

Tiempo::Tiempo()

{
    QTimer *cronometro= new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(Activartiempo()));
    cronometro->start(500);
}

int Tiempo::getTime()
{
    return contador;
}
void Tiempo::Activartiempo(){
   contador++;
   if(contador>9) contador=0;

}
