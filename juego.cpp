#include "juego.h"
#include "ui_juego.h"
#include "mainwindow.h"

Juego::Juego(QWidget *parent,const QString usuario,const QString contra, QString nivel, QString modo)
    : QMainWindow(parent), usuario(usuario), contra(contra), nivel(nivel), modo(modo)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,810,600);     //asigna el rectangulo que encierra la scene
    ui->graphicsView1->setScene(scene);
    scene->addRect(scene->sceneRect());
    scene->setBackgroundBrush(QPixmap(":/Photos/asfalto.jpg"));

    QTimer *cronometro= new QTimer(this);
    connect(cronometro,SIGNAL(timeout()),this,SLOT(activartiempo()));
    cronometro->start(1000);
    usuario1=usuario;
    contra1=contra;
    nivel1=nivel;
    contador=0;
    t1=0;
    t2=0;
    ingresarnivel(nivel1);
    music= new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/user/Documents/Parking_simulator/sonidos/music.mp3"));
    music->play();
    ban=true;
    ban2=0;
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
    if(contador>180){
        contador=0;
        QMessageBox::critical(this,"LOSER","SE ACABÓ EL TIEMPO.");
        personaje->perder();
    }
}

void Juego::ingresarnivel(QString nivel1)
{
    if(nivel1 == "1"){ // nivel 1

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
        obstaculos.push_back(new Jardin(2,211,57,10,595));scene->addItem(obstaculos.back());//bordes horizontales
        obstaculos.push_back(new Jardin(2,211,57,207,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,414,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,621,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(4,100,117,600,50));scene->addItem(obstaculos.back());// carros
        obstaculos.push_back(new Jardin(3,117,100,600,380));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(3,117,100,70,230));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(6,100,117,70,350));scene->addItem(obstaculos.back());
        vidas.push_back(new Vidas(30,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(60,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(90,20));scene->addItem(vidas.back());

        carrera= new Jardin(7,100,50,650,220); scene->addItem(carrera);
        personaje= new Carro();scene->addItem(personaje);
        volante= new Volante(100,540);scene->addItem(volante);
        velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro);
        aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja);


        l1= new Lineas(160,8,350,180); scene->addItem(l1);
        l2= new Lineas(160,8,350,320); scene->addItem(l2);
        l3= new Lineas(160,8,350,460); scene->addItem(l3);
        l4= new Lineas(160,8,-200,320); scene->addItem(l4);
        l5= new Lineas(160,8,-200,180); scene->addItem(l5);



    }
    if(nivel1 == "2"){ //Diseño del nivel 2


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
        obstaculos.push_back(new Jardin(2,211,57,10,595));scene->addItem(obstaculos.back());//bordes horizontales
        obstaculos.push_back(new Jardin(2,211,57,207,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,414,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,621,595));scene->addItem(obstaculos.back());

        obstaculos.push_back(new Jardin(4,100,117,500,400));scene->addItem(obstaculos.back());// carros
        obstaculos.push_back(new Jardin(6,100,117,550,200));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(3,117,100,420,200));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(3,117,100,200,400));scene->addItem(obstaculos.back());

        vidas.push_back(new Vidas(30,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(60,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(90,20));scene->addItem(vidas.back());

        carrera= new Jardin(7,100,100,350,40); scene->addItem(carrera);
        personaje= new Carro();scene->addItem(personaje); // añadir el carro a la escena
        volante= new Volante(100,540);scene->addItem(volante); // añadir el volante a la escena
        velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro); // añadir el velocimetro a la escena
        aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja); // añadir la aguja del velocimetro a la escena


        l5= new Lineas(8,100,80,470); scene->addItem(l5);
        l6= new Lineas(8,100,-80,470); scene->addItem(l6);

    }
    if(nivel1 == "3"){ //Diseño de nivel 3

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
        obstaculos.push_back(new Jardin(2,211,57,10,-30));scene->addItem(obstaculos.back());//bordes horizontales
        obstaculos.push_back(new Jardin(2,211,57,207,-30));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,414,-30));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,621,-30));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,10,595));scene->addItem(obstaculos.back());//bordes horizontales
        obstaculos.push_back(new Jardin(2,211,57,207,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,414,595));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,621,595));scene->addItem(obstaculos.back());


        obstaculos.push_back(new Jardin(2,211,57,200,360));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(2,211,57,400,360));scene->addItem(obstaculos.back());//Jardin


        obstaculos.push_back(new Jardin(4,100,117,650,40));scene->addItem(obstaculos.back());// carros
        //obstaculos.push_back(new Jardin(6,100,117,650,150));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(3,117,100,60,40));scene->addItem(obstaculos.back());
        //obstaculos.push_back(new Jardin(3,117,100,60,140));scene->addItem(obstaculos.back());


        obstaculos.push_back(new Jardin(5,100,107,250,250));scene->addItem(obstaculos.back());
        obstaculos.push_back(new Jardin(5,100,107,470,250));scene->addItem(obstaculos.back());

        vidas.push_back(new Vidas(30,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(60,20));scene->addItem(vidas.back());
        vidas.push_back(new Vidas(90,20));scene->addItem(vidas.back());

        carrera= new Jardin(7,100,50,360,250); scene->addItem(carrera);
        personaje= new Carro();scene->addItem(personaje);
        volante= new Volante(100,540);scene->addItem(volante);
        velocimetro= new Velocimetro(1,300,50,680,570); scene->addItem(velocimetro);
        aguja= new Velocimetro(2,250,130,685,590); scene->addItem(aguja);



        l3= new Lineas(8,100,50,260); scene->addItem(l3);
        l4= new Lineas(8,100,-60,260); scene->addItem(l4);
        l5= new Lineas(8,100,160,260); scene->addItem(l5);
        l6= new Lineas(8,100,-160,260); scene->addItem(l6);

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
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            QMessageBox::critical(this,"Lo siento","No lo lograste");
                            personaje->perder();
                            contador=0;
                        }
                    }
                }
                if(personaje->getPosx()>=698 && personaje->getPosx()<700
                        ){

                    if(modo=="1"){
                    close();
                    music->stop();
                    nivel1="2";
                    juego= new Juego(this,usuario,contra, nivel1,"1");
                    juego->show();}
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
            }else if (event->key() == Qt::Key_A){
                personaje->Left();
                volante->rotar_left();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                        QMessageBox::critical(this,"Lo siento","No lo lograste");
                        personaje->perder();
                        contador=0;}

                    }
                }
                if(personaje->getPosx()>=698 && personaje->getPosx()<700
                        ){
                    if(modo=="1"){
                        close();
                        music->stop();
                        nivel1="2";
                        juego= new Juego(this,usuario,contra, nivel1,"1");
                        juego->show();
                    }
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            hide();
                            file.close();
                            file2.close();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
            }else if (event->key() == Qt::Key_W){
                personaje->Up();
                aguja->acelerar();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{
                            QMessageBox::critical(this,"Lo siento","No lo lograste");
                            personaje->perder();
                            contador=0;
                        }

                    }
                }
                if(personaje->getPosx()>=698 && personaje->getPosx()<700
                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    nivel1="2";
                    juego= new Juego(this,usuario,contra, nivel1,"1");
                    juego->show();
                    }
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
            }else if (event->key() == Qt::Key_S){

                    personaje->Down();
                    aguja->retroceder();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                            if(!vidas.isEmpty()){
                                personaje->perder();
                                delete vidas.takeFirst();

                            }else{
                                QMessageBox::critical(this,"Lo siento","No lo lograste");
                                personaje->perder();
                                contador=0;
                            }
                        }
                    }
                    if((personaje->getPosx()>=698 && personaje->getPosx()<700) && (personaje->getPosy()>=250 && personaje->getPosy()<270 ) //&& personaje->getPosy()==220
                            ){
                        if(modo=="1"){
                            close();
                            music->stop();
                            nivel1="2";
                            juego= new Juego(this,usuario,contra, nivel1,"1");
                            juego->show();
                        }
                        else if(modo=="2"){
                            music->stop();
                            QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                             QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                            file.open(QIODevice::ReadOnly | QIODevice::Text);
                            file2.open(QIODevice::WriteOnly);
                            QTextStream escribir(&file2);

                            QTextStream datosArchivo(&file);
                                while(!datosArchivo.atEnd()){
                                    datosArchivo>>contador1;
                                    if(contador1<=contador){
                                    escribir<<contador;
                                    QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                                }
                                file.close();
                                file2.close();
                                hide();
                                MainWindow *menu= new MainWindow;
                                menu->show();


                                }



                        }



            }
        }
        if(nivel=="2"){
            if(event->key() == Qt::Key_D){
                personaje->Rigth();
                volante->rotar_right();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                            contador=0;
                        }
                    }
                }
                if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>300 ) //&& personaje->getPosy()==220
                        ){
                    if(modo=="1"){
                        close();
                        music->stop();
                        nivel1="2";
                        juego= new Juego(this,usuario,contra, nivel1);
                        juego->show();}
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();

                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }

                }
            }else if (event->key() == Qt::Key_A){
                personaje->Left();
                volante->rotar_left();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else {
                            personaje->perder();
                            contador=0;
                        }

                    }
                }
                if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>300 ) //&& personaje->getPosy()==220
                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    nivel1="2";
                    juego= new Juego(this,usuario,contra, nivel1);
                    juego->show();}
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }

                }
            }else if (event->key() == Qt::Key_W){
                personaje->Up();
                aguja->acelerar();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{

                            personaje->perder();
                            contador=0;
                        }

                    }
                }
                if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 ) //&& personaje->getPosy()==220
                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    nivel1="2";
                    juego= new Juego(this,usuario,contra, nivel1);
                    juego->show();}
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }

                }
            }else if (event->key() == Qt::Key_S){

                    personaje->Down();
                    aguja->retroceder();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                            personaje->perder();
                            if(!vidas.isEmpty()){
                                delete vidas.takeFirst();

                            }else{

                                personaje->perder();
                                contador=0;
                            }
                        }
                    }
                    if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 )

                            ){
                        if(modo=="1"){
                        close();
                        music->stop();
                        nivel1="2";
                        juego= new Juego(this,usuario,contra, nivel1);
                        juego->show();}
                        else if(modo=="2"){
                            music->stop();
                            QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                             QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                            file.open(QIODevice::ReadOnly | QIODevice::Text);
                            file2.open(QIODevice::WriteOnly);
                            QTextStream escribir(&file2);

                            QTextStream datosArchivo(&file);
                                while(!datosArchivo.atEnd()){
                                    datosArchivo>>contador1;
                                    if(contador1<=contador){
                                    escribir<<contador;
                                    QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                                }
                                file.close();
                                file2.close();
                                hide();
                                MainWindow *menu= new MainWindow;
                                menu->show();


                                    }

                    }

            }
        }

        if(nivel=="3"){
            if(event->key() == Qt::Key_D){
                personaje->Rigth();
                volante->rotar_right();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                            contador=0;
                        }
                    }
                }
                if((personaje->getPosy()>=-0 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 )

                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    QMessageBox msgBox;
                    msgBox.setText("FELICIDADES?");
                    msgBox.setInformativeText("Deseas volver a jugar?. ");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Close);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret=msgBox.exec();
                    switch (ret) {
                        case QMessageBox::Yes:
                        music->stop();
                        close();
                        nivel1="1";
                        juego= new Juego(this,usuario,contra, nivel1);
                        juego->show();


                        break;

                    case QMessageBox::Close:
                            close();
                        break;
                    }

                    }
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
                }else if (event->key() == Qt::Key_A){
                personaje->Left();
                volante->rotar_left();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{personaje->perder();
                        contador=0;}

                    }
                }
                if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 )

                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    QMessageBox msgBox;
                    msgBox.setText("FELICIDADES?");
                    msgBox.setInformativeText("Deseas volver a jugar?. ");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Close);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret=msgBox.exec();
                    switch (ret) {
                        case QMessageBox::Yes:
                        music->stop();
                        close();
                        nivel1="1";
                        juego= new Juego(this,usuario,contra, nivel1);
                        juego->show();


                        break;

                    case QMessageBox::Close:
                            close();
                        break;
                    }

                    }
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
            }else if (event->key() == Qt::Key_W){
                personaje->Up();
                aguja->acelerar();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                            contador=0;
                        }

                    }
                }
                if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 )

                        ){
                    if(modo=="1"){
                    close();
                    music->stop();
                    QMessageBox msgBox;
                    msgBox.setText("FELICIDADES?");
                    msgBox.setInformativeText("Deseas volver a jugar?. ");
                    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Close);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    int ret=msgBox.exec();
                    switch (ret) {
                        case QMessageBox::Yes:
                        music->stop();
                        close();
                        nivel1="1";
                        juego= new Juego(this,usuario,contra, nivel1);
                        juego->show();


                        break;

                    case QMessageBox::Close:
                            close();
                        break;
                    }

                }
                    else if(modo=="2"){
                        music->stop();
                        QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                         QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                        file.open(QIODevice::ReadOnly | QIODevice::Text);
                        file2.open(QIODevice::WriteOnly);
                        QTextStream escribir(&file2);

                        QTextStream datosArchivo(&file);
                            while(!datosArchivo.atEnd()){
                                datosArchivo>>contador1;
                                if(contador1<=contador){
                                escribir<<contador;
                                QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                            }
                            file.close();
                            file2.close();
                            hide();
                            MainWindow *menu= new MainWindow;
                            menu->show();


                                }
                }
            }else if (event->key() == Qt::Key_S){

                    personaje->Down();
                    aguja->retroceder();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                                personaje->perder();
                            if(!vidas.isEmpty()){
                                delete vidas.takeFirst();

                            }else{
                                personaje->perder();
                                contador=0;
                            }
                        }
                    }
                    if((personaje->getPosy()>=70 && personaje->getPosy()<=90) && (personaje->getPosx()<=450 && personaje->getPosx()>350 )

                            ){
                        if(modo=="1"){
                        close();
                        music->stop();
                        QMessageBox msgBox;
                        msgBox.setText("FELICIDADES?");
                        msgBox.setInformativeText("Deseas volver a jugar?. ");
                        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Close);
                        msgBox.setDefaultButton(QMessageBox::Yes);
                        int ret=msgBox.exec();
                        switch (ret) {
                            case QMessageBox::Yes:
                            music->stop();
                            close();
                            nivel1="1";
                            juego= new Juego(this,usuario,contra, nivel1);
                            juego->show();


                            break;

                        case QMessageBox::Close:
                                close();
                            break;
                        }

                    }
                        else if(modo=="2"){
                            music->stop();
                            QFile file("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                             QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/multijugador.txt");
                            file.open(QIODevice::ReadOnly | QIODevice::Text);
                            file2.open(QIODevice::WriteOnly);
                            QTextStream escribir(&file2);

                            QTextStream datosArchivo(&file);
                                while(!datosArchivo.atEnd()){
                                    datosArchivo>>contador1;
                                    if(contador1<=contador){
                                    escribir<<contador;
                                    QMessageBox::information(this,"NO LO SUPERASTE","No superaste el mejor tiempo");}

                                }
                                file.close();
                                file2.close();
                                hide();
                                MainWindow *menu= new MainWindow;
                                menu->show();


                                    }
                    }
            }
        }

}


void Juego::keyReleaseEvent(QKeyEvent *event){
    if(ban){
        if(nivel=="1"){
            if(event->key() == Qt::Key_D){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){

                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                        }
                    }
                }
            }else if (event->key() == Qt::Key_A){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){

                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{personaje->perder();}

                    }
                }
            }
            if (event->key() == Qt::Key_W){
                personaje->noUp();
                aguja->mitad();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();;
                        }

                    }
                }
            }else if (event->key() == Qt::Key_S){

                    personaje->noDown();
                    aguja->mitad();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                            if(!vidas.isEmpty()){
                                delete vidas.takeFirst();

                            }else{
                                personaje->perder();
                            }
                        }
                    }

            }
        }
        if(nivel=="2"){
            if(event->key() == Qt::Key_D){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){

                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                        }
                    }
                }
            }else if (event->key() == Qt::Key_A){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        personaje->perder();
                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{personaje->perder();}

                    }
                }
            }
            if (event->key() == Qt::Key_W){
                personaje->noUp();
                aguja->mitad();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{
                           personaje->perder();
                        }

                    }
                }
            }else if (event->key() == Qt::Key_S){

                    personaje->noDown();
                    aguja->mitad();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                            if(!vidas.isEmpty()){
                                delete vidas.takeFirst();

                            }else{
                                personaje->perder();
                            }
                        }
                    }

            }
        }
        if(nivel=="3"){
            if(event->key() == Qt::Key_D){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){

                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                        }
                    }
                }
            }else if (event->key() == Qt::Key_A){
                volante->soltar();

                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){

                        if(!vidas.isEmpty()){
                            delete vidas.takeFirst();
                        }
                        else{personaje->perder();}

                    }
                }
            }
            if (event->key() == Qt::Key_W){
                personaje->noUp();
                aguja->mitad();
                for (int j=0;j<obstaculos.size();j++) {
                    if(personaje->collidesWithItem(obstaculos.at(j))){
                        if(!vidas.isEmpty()){

                            delete vidas.takeFirst();
                        }
                        else{
                            personaje->perder();
                        }

                    }
                }
            }else if (event->key() == Qt::Key_S){

                    personaje->noDown();
                    aguja->mitad();
                    for (int j=0;j<obstaculos.size();j++) {
                        if( personaje->collidesWithItem(obstaculos.at(j))){
                            if(!vidas.isEmpty()){
                                delete vidas.takeFirst();

                            }else{
                                personaje->perder();
                            }
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

     close();

    juego= new Juego(this,usuario,contra,nivel,"2");
    juego->show();
    if(ban2){
        QMessageBox::information(this,"v","f");

    }


    }


    else{
        QMessageBox::warning(this,"ERROR!","Nivel ingresado no es corrrecto");
    }
}

