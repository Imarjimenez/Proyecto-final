#ifndef TIEMPO_H
#define TIEMPO_H

#include <QThread>
#include <QTimer>
class Tiempo : public QThread
{
    Q_OBJECT
public:
    Tiempo();
    int getTime();
public slots:
    void Activartiempo();

private:
    int contador=0;
    QTimer *cronometro;
};

#endif // TIEMPO_H
