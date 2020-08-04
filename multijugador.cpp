#include "multijugador.h"
#include "ui_multijugador.h"


Multijugador::Multijugador(QWidget *parent,const QString usuario,const QString contra,const QString nivel) :
    Juego(parent,usuario,contra,nivel),usuario(usuario), contra(contra), nivel(nivel),
    ui(new Ui::Multijugador)
{
    ui->setupUi(this);
    s = new QGraphicsScene;
    s->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
    ui->graphicsView->setScene(s);
    s->addRect(s->sceneRect());

    nivelasignado(nivel);
    activartiempo();

}

Multijugador::~Multijugador()
{
    delete ui;

}

void Multijugador::nivelasignado(QString nivel)
{
    if(nivel == "1"){ // nivel 1
        s->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
        ui->graphicsView->setScene(s);
        s->addRect(s->sceneRect());
        s->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

        ingresarnivel("1");


    }
    if(nivel1 == "2"){ //Diseño del nivel 2
        s->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
        ui->graphicsView->setScene(s);
        s->addRect(s->sceneRect());
        s->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

       ingresarnivel("2");

    }
    if(nivel1 == "3"){ //Diseño de nivel 3
        s->setSceneRect(0,0,810,600);
        ui->graphicsView->setScene(s);
        s->addRect(s->sceneRect());
        s->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

        ingresarnivel("3");


    }
}

