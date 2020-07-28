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

        if(nivel1 == "1"){ // nivel 1
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

            vidas.push_back(new Vidas(621,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(10,480);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,580,500); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,577,518); scene->addItem(aguja);







        }
        if(nivel1 == "2"){ //Diseño del nivel 2
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

            vidas.push_back(new Vidas(621,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje); // añadir el carro a la escena
            volante= new Volante(10,480);scene->addItem(volante); // añadir el volante a la escena
            velocimetro= new Velocimetro(1,300,50,580,500); scene->addItem(velocimetro); // añadir el velocimetro a la escena
            aguja= new Velocimetro(2,250,130,577,518); scene->addItem(aguja); // añadir la aguja del velocimetro a la escena


        }
        if(nivel1 == "3"){ //Diseño de nivel 3
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

            vidas.push_back(new Vidas(621,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(10,480);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,580,500); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,577,518); scene->addItem(aguja);


        }
        if(nivel1 =="4"){ //Diseño del nivel 4
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

            vidas.push_back(new Vidas(621,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(621,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(10,480);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,580,500); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,577,518); scene->addItem(aguja);


        }


}



void Juego::keyPressEvent(QKeyEvent *event)
{


    if(nivel=="1"){

        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                    for (int j=0;j<vidas.size();j++) {
                        if(personaje->collidesWithItem(obstaculos.at(i))){
                            scene->removeItem(vidas.at(j));
                            vidas.removeFirst();
                        }
                    }






                }

            }

       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){
                    for (int j=0;j<vidas.size();j++) {
                        if(personaje->collidesWithItem(obstaculos.at(i))){
                            scene->removeItem(vidas.at(j));
                            vidas.removeFirst();
                        }
                    }

                }

            }
        }
        if (event->key() == Qt::Key_W){
            personaje->Up(vel);

            aguja->transformOriginPoint();
            aguja->setRotation(60);



                    for (int j=0;j<obstaculos.size();j++) {

                        if(personaje->collidesWithItem(obstaculos.at(j))){

                            while(!vidas.isEmpty()){
                                delete vidas.takeFirst();
                            }


                        }
                        }





        }
        if (event->key() == Qt::Key_S){
            personaje->Down(vel);
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){
                    for(int j=0;j<vidas.size();j++){
                    scene->removeItem(vidas.at(j));

                    }

                }

            }
        }
    }
    if(nivel=="2"){
        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }

       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
        if (event->key() == Qt::Key_W){
            personaje->Up(vel);
            aguja->setTransformOriginPoint(150,400);
            aguja->setRotation(60);

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }


        }
        if (event->key() == Qt::Key_S){
            personaje->Down(vel);
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
    }
    if(nivel=="3"){
        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }

       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
        if (event->key() == Qt::Key_W){
            personaje->Up(vel);
            aguja->setTransformOriginPoint(150,400);
            aguja->setRotation(60);

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){


                }

            }


        }
        if (event->key() == Qt::Key_S){
            personaje->Down(vel);
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
    }
    if(nivel=="4"){
        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }

       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
        if (event->key() == Qt::Key_W){
            personaje->Up(vel);
            aguja->setTransformOriginPoint(150,400);
            aguja->setRotation(60);

            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }


        }
        if (event->key() == Qt::Key_S){
            personaje->Down(vel);
            for (int i=0;i<obstaculos.size();i++) {
                if(personaje->collidesWithItem(obstaculos.at(i))){

                }

            }
        }
    }





}




void Juego::on_pushButton_clicked()
{

}
