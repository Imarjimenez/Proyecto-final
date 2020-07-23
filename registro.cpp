#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    scene= new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0,626,382);
    scene->setBackgroundBrush(QPixmap(":/Photos/fondo2.jpg"));
}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_pushButton_clicked()
{
    QString usuario=ui->Usuario->text();
    QString contra=ui->Contra->text();
    QString nivel="1";


    QFile file("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");
     QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream datosArchivo(&file);
        while(!datosArchivo.atEnd()){
            datosArchivo>>usu_archivo;

            if(usuario==usu_archivo){
                QMessageBox::warning(this,"Intente otra vez","El usuario ya existe");
            }
            else{
                registro=true;
            }



        }
    file2.open(QIODevice::WriteOnly|QIODevice::Append);

    QTextStream escribir(&file2);

    if(registro==true){

        escribir<<usuario<<"  "<<contra<<"  "<<nivel<<endl;
        hide();
    }





    file.close();

}







