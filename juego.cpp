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
            obstaculos.push_back(new Jardin(4,100,117,600,100));scene->addItem(obstaculos.back());// carros
            obstaculos.push_back(new Jardin(3,117,100,600,300));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(3,117,100,70,200));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(6,100,117,70,350));scene->addItem(obstaculos.back());
            vidas.push_back(new Vidas(70,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(100,540);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja);







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
            obstaculos.push_back(new Jardin(4,100,117,500,70));scene->addItem(obstaculos.back());// carros
            obstaculos.push_back(new Jardin(6,100,117,600,200));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(3,117,100,70,200));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(3,117,100,200,70));scene->addItem(obstaculos.back());

            vidas.push_back(new Vidas(70,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje); // añadir el carro a la escena
            volante= new Volante(100,540);scene->addItem(volante); // añadir el volante a la escena
            velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro); // añadir el velocimetro a la escena
            aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja); // añadir la aguja del velocimetro a la escena


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

            obstaculos.push_back(new Jardin(2,211,57,10,350));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(2,211,57,207,350));scene->addItem(obstaculos.back());//Jardin
            obstaculos.push_back(new Jardin(2,211,57,414,350));scene->addItem(obstaculos.back());

            obstaculos.push_back(new Jardin(4,100,117,500,70));scene->addItem(obstaculos.back());// carros
            obstaculos.push_back(new Jardin(6,100,117,600,200));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(3,117,100,70,200));scene->addItem(obstaculos.back());
            obstaculos.push_back(new Jardin(3,117,100,200,70));scene->addItem(obstaculos.back());

            vidas.push_back(new Vidas(70,30));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,60));scene->addItem(vidas.back());
            vidas.push_back(new Vidas(70,90));scene->addItem(vidas.back());

            personaje= new Carro();scene->addItem(personaje);
            volante= new Volante(100,540);scene->addItem(volante);
            velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro);
            aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja);


        }



}



void Juego::keyPressEvent(QKeyEvent *event)
{


    if(nivel=="1"){

        if(event->key() == Qt::Key_D){
            personaje->Rigth();
            volante->rotar_right();

            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }

                }
                }


       }
        if (event->key() == Qt::Key_A){

            personaje->Left();
            volante->rotar_left();
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }





        }
        if (event->key() == Qt::Key_W){
            personaje->Up();
            aguja->setRotation(-40);




                    for (int j=0;j<obstaculos.size();j++) {

                        if(personaje->collidesWithItem(obstaculos.at(j))){

                            if(!vidas.isEmpty()){
                                vidas.pop_back();
                            }


                        }
                        }





        }
        if (event->key() == Qt::Key_S){
            personaje->Down();
            aguja->setRotation(-90);
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }


        }
    }
    if(nivel=="2"){
        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }


       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }

        }
        if (event->key() == Qt::Key_W){
            personaje->Up();


            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }



        }
        if (event->key() == Qt::Key_S){
            personaje->Down();
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }

        }
    }
    if(nivel=="3"){
        if(event->key() == Qt::Key_D){
            personaje->Rigth();

            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }


       }
        if (event->key() == Qt::Key_A){
            personaje->Left();
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }

        }
        if (event->key() == Qt::Key_W){
            personaje->Up();
            aguja->setTransformOriginPoint(150,400);
            aguja->setRotation(60);

            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }



        }
        if (event->key() == Qt::Key_S){
            personaje->Down();
            for (int j=0;j<obstaculos.size();j++) {

                if(personaje->collidesWithItem(obstaculos.at(j))){

                    if(!vidas.isEmpty()){
                        vidas.pop_back();
                    }


                }
                }

        }
    }

}





void Juego::on_pushButton_clicked()
{

    QFile file("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream escribir(&file);

    QTextStream datosArchivo(&file);
    QMessageBox msgBox;
    msgBox.setText("ESTÁ SEGURO QUE DESEA GUARDAR EL NIVEL?");
    msgBox.setInformativeText("Recuerde que podrás acceder al juego guardado desde el menú principal. ");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret=msgBox.exec();
    switch (ret) {
        case QMessageBox::Yes:
        while(!datosArchivo.atEnd()){
                datosArchivo>>usuario>>contra>>nivel;

         }


            file.close();
        break;

        case QMessageBox::No:

        break;
    }

}

void Juego::on_pushButton_2_clicked()
{
    QString N=QInputDialog::getText(this,"Multijugador: Recuerde que son tres niveles","Ingrese el nivel donde desea jugar: ");

    if(N=="1" || N=="2" || N=="3"){
    nivel=N;
    hide();
    juego= new Juego(this,usuario1,contra1, nivel);
    juego->show();}
    else{
        QMessageBox::warning(this,"ERROR!","Nivel ingresado no es corrrecto");
    }
}
