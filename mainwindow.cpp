#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MSEC 10
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

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

MainWindow::~MainWindow()
{

    delete scene;
    delete ui;
}



void MainWindow::activartiempo()
{
    ui->lcdNumber->display(contador);
    contador++;
    if(contador>180) contador=0;
}

void MainWindow::niveles()
{
    if(nivel == 0){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
            ui->graphicsView->setScene(scene);
            scene->setBackgroundBrush(QPixmap(":/Photos/menup.png"));

        }
        if(nivel == 1){ // menu
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

            numero1= new Jardin(1,67,207,0,300);
            numero2= new Jardin(1,67,207,0,480);
            numero3= new Jardin(1,67,207,0,120);
            numero4= new Jardin(2,67,207,0,-40);
            scene->addItem(numero1); scene->addItem(numero2);scene->addItem(numero3);

        }
        if(nivel == 2){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }
        if(nivel == 3){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
            ui->graphicsView->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }
        if(nivel==4){
            scene->setSceneRect(0,0,978,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView->setScene(scene);

            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/fondo.jpg"));

        }

}



void MainWindow::keyPressEvent(QKeyEvent *event)
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

