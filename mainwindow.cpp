#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1200,700);
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);




    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(20);

    QTimer *cronometro= new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(activartiempo()));
    cronometro->start(1000);

    personaje = new Carro();
    scene->addItem(personaje);
    numero1= new Jardin(400,400,0,200);

    scene->addItem(numero1);

}

MainWindow::~MainWindow()
{

    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{

}

void MainWindow::activartiempo()
{
    ui->lcdNumber->display(contador);
    contador++;
    if(contador>180) contador=0;
}





void MainWindow::keyPressEvent(QKeyEvent *event)
{


            if (event->key() == Qt::Key_D ){
                personaje->Rigth();
            }
            if (event->key() == Qt::Key_A ){
                personaje->Left();
            }
            if (event->key() == Qt::Key_W){
                personaje->Up();

            }










}

QList<Vidas *> MainWindow::eliminar(QList<Vidas *> lista, int pos)
{
    QList<Vidas*> aux;
    for (int i=0;i<lista.size();i++) {
        if(i!=pos){
            aux.push_back(lista.at(i));
        }

    }
    return aux;
}

//void MainWindow::niveles(){
//    if(x == 0){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/inicio"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x == 1){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/fondo"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x == 2){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/fondo2"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x == 3){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/fondo3"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x==4){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/fondo4"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x==5){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/fondo5"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//    if(x==6){
//        scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
//        ui->graphicsView->setScene(scene);

//        scene->addRect(scene->sceneRect());
//        scene->setBackgroundBrush(QPixmap(":/final"));
//        ui->graphicsView->resize(scene->width(),scene->height());
//        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
//    }
//}

