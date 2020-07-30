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
#include <QInputDialog>




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

    void ingresarnivel();


public slots:

    void activartiempo();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Juego *ui;


    QGraphicsScene *scene;
    Carro *personaje;//scene que muestra los objetos animados
    QTimer *cronometro;
    Volante *volante;
    Velocimetro *velocimetro, *aguja;
    QList<Vidas *> vidas;
    QList<Jardin *> obstaculos;
    Juego *juego;


    int contador=0;
    bool ban=true;
    float vel=1;


    void keyPressEvent(QKeyEvent *event);

};

#endif // JUEGO_H
