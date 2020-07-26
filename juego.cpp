#include "juego.h"
#include "ui_juego.h"


Juego::Juego(QWidget *parent,const QString usuario,const QString contra, QString nivel)
    : QMainWindow(parent), usuario(usuario), contra(contra), nivel(nivel)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;


    QTimer *cronometro= new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(activartiempo()));
    cronometro->start(1000);

    usuario1=usuario;
    contra1=contra;
    nivel1=nivel;

    ingresarnivel();







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

void Juego::ingresarnivel()
{

        if(nivel == "1"){ // nivel 1
            scene->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

            obstaculos.push_back(new Jardin(1,67,207,-30,290));scene->addItem(obstaculos.back());//bordes verticales
            obstaculos.push_back(new Jardin(1,67,207,-30,470));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,150));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,-10));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,-40));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,120));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,480));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//bordes horizontales
            obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(10,480);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,580,500); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,577,518); scene->addItem(aguja);


        }
        if(nivel == "2"){ //Diseño del nivel 2
            scene->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

            obstaculos.push_back(new Jardin(1,67,207,-30,290));scene->addItem(obstaculos.back());//bordes verticales
            obstaculos.push_back(new Jardin(1,67,207,-30,470));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,150));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,-10));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,-40));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,120));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,480));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//bordes horizontales
            obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());

            personaje= new Carro();
            volante= new Volante(10,480);

        }
        if(nivel == "3"){ //Diseño de nivel 3
            scene->setSceneRect(0,0,810,600);
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

            obstaculos.push_back(new Jardin(1,67,207,-30,290));scene->addItem(obstaculos.back());//bordes verticales
            obstaculos.push_back(new Jardin(1,67,207,-30,470));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,150));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,-10));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,-40));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,120));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,480));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//bordes horizontales
            obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());

            personaje= new Carro();
            volante= new Volante(10,480);

        }
        if(nivel=="4"){ //Diseño del nivel 4
            scene->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
            ui->graphicsView1->setScene(scene);
            scene->addRect(scene->sceneRect());
            scene->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

            obstaculos.push_back(new Jardin(1,67,207,-30,290));scene->addItem(obstaculos.back());//bordes verticales
            obstaculos.push_back(new Jardin(1,67,207,-30,470));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,150));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,-30,-10));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,-40));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,120));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(1,67,207,770,480));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//bordes horizontales
            obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());

            personaje= new Carro();
            volante= new Volante(10,480);

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
