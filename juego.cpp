#include "juego.h"
#include "ui_juego.h"


Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView1->setScene(scene);

    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QPixmap(":/Photos/menup.jpg"));



    QTimer *cronometro= new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(activartiempo()));
    cronometro->start(1000);

    QTimer *tiempo= new QTimer(this);
    connect(tiempo,SIGNAL(timeout()),this,SLOT(actualizar()));
    tiempo->start(1000);
    personaje = new Carro();


  scene->addItem(personaje);








}

Juego::~Juego()
{

    delete scene;
    delete ui;
}



void Juego::activartiempo()
{
    ui->lcdNumber->display(contador);
    contador++;
    if(contador>180) contador=0;
}

void Juego::niveles()
{
    if(nivel == 0){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
            ui->graphicsView1->setScene(scene);
            scene->setBackgroundBrush(QPixmap(":/Photos/menup.png"));

        }
        if(nivel == 1){ // menu
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

            obstaculos.push_back(new Jardin(1,67,207,-10,320));scene->addItem(obstaculos.back());//verticales
            obstaculos.push_back(new Jardin(1,67,207,-10,470));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-10,150));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-10,-10));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,-40));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,120));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,480));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//horrizontales
            obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());



        }
        if(nivel == 2){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }
        if(nivel == 3){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }
        if(nivel==4){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);

            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }

}



void Juego::keyPressEvent(QKeyEvent *event)
{


            if(event->key() == Qt::Key_D){
                personaje->Rigth();

           }
            if (event->key() == Qt::Key_A){
                personaje->Left();
            }
            if (event->key() == Qt::Key_W){
                personaje->Up(vel);

            }
            if (event->key() == Qt::Key_S){
                personaje->Down(vel);
            }




}

QList<Vidas *> Juego::eliminar(QList<Vidas *> lista, int pos)
{
    QList<Vidas*> aux;
    for (int i=0;i<lista.size();i++) {
        if(i!=pos){
            aux.push_back(lista.at(i));
        }

    }
    return aux;
}
