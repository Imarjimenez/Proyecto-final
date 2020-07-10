#include "tiempo.h"

Tiempo::Tiempo(int segundos, QObject *parent)
    : QThread (parent)
{
    mSegundos = segundos;
}
void Tiempo::run(){
    while(true){
        emit timeOut();
        QThread::msleep(mSegundos);
    }
}
