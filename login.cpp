#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,626,382);
    scene->setBackgroundBrush(QPixmap(":/Photos/fondo2.jpg"));

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{

    QString usuario=ui->Usuario->text();
    QString contra=ui->Contra->text();
    QString nivel="1";
    QList<QString> cont_nivel ={contra,nivel};


    QFile file("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream escribir(&file);

    QTextStream datosArchivo(&file);
        while(!datosArchivo.atEnd()){
            datosArchivo>>usu_archivo>>contra_archivo>>niv_archivo;

            if(usuario==usu_archivo){

                if(contra==contra_archivo){
                    ban=0;
                    hide();
                    juego= new Juego(this,usu_archivo,contra_archivo, niv_archivo);
                    juego->show();

                }



            }



        }
        if(ban==1){
            QMessageBox::warning(this,"No es posible","Datos inconsistentes");

        }


        file.close();








}

