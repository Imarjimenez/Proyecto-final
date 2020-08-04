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
#include "lineas.h"
#include <QKeyEvent>
#include <QImage>
#include <QMessageBox>
#include <QInputDialog>
#include <QMediaPlayer>

namespace Ui {
class Juego;
}

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit Juego( QWidget *parent = 0);
    Juego(QWidget *parent=0,const QString usuario="",const QString contra="",const QString nivel="", const QString modo="");

    ~Juego();
    QString usuario;
    QString contra;
    QString nivel;
    QString usuario1;
    QString contra1;
    QString nivel1;
    QString modo;
    QString contador1;

    void ingresarnivel(QString nivel1);

public slots:
    void activartiempo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Juego *ui;
    QGraphicsScene *scene;
    Carro *personaje;
    QTimer *cronometro;
    Volante *volante;
    Velocimetro *velocimetro, *aguja;
    QList<Vidas *> vidas;
    QList<Jardin *> obstaculos;
    Lineas *l1,*l2,*l3,*l4,*l5,*l6;
    Jardin *carrera;
    Juego *juego;
    QMediaPlayer *music;
    int contador,t1,t2;
    bool ban;
    int ban2;
    float vel=1;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // JUEGO_H
