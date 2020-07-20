#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "carro.h"
#include "jardin.h"
#include "vidas.h"
#include <QKeyEvent>
#include <QImage>
#include <QMessageBox>
#include <QLCDNumber>



namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego(QWidget *parent = 0);
    ~Juego();

public slots:

    void activartiempo();
private slots:
    void niveles();


private:
    Ui::Juego *ui;
             //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;
    Carro *personaje;//scene que muestra los objetos animados
    QTimer *cronometro, *tiempo;

    QList<Vidas *> vidas;
    QList<Jardin *> obstaculos;
    int contador=0;

    float vel=1;

    int nivel=0;


    void keyPressEvent(QKeyEvent *event);
    QList<Vidas*> eliminar(QList<Vidas*>lista,int pos);
};

#endif // JUEGO_H
