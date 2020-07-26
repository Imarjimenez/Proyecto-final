#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include "carro.h"
#include "jardin.h"
#include "vidas.h"
#include "volante.h"
#include "velocimetro.h"
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
    explicit Juego( QWidget *parent = 0);
    Juego(QWidget *parent=0,const QString usuario="",const QString contra="",const QString nivel="");

    ~Juego();
    QString usuario;
    QString contra;
    QString nivel;
    QString usuario1;
    QString contra1;
    QString nivel1;


public slots:

    void activartiempo();



private:
    Ui::Juego *ui;


    QGraphicsScene *scene;
    Carro *personaje;//scene que muestra los objetos animados
    QTimer *cronometro;
    Volante *volante;
    Velocimetro *velocimetro, *aguja;
    QList<Vidas *> vidas;
    QList<Jardin *> obstaculos;
    int contador=0;

    float vel=1;


    void ingresarnivel();
    void keyPressEvent(QKeyEvent *event);
    QList<Vidas*> eliminar(QList<Vidas*>lista,int pos);
};

#endif // JUEGO_H
