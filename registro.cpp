#include "registro.h"
#include "ui_registro.h"
#include <QApplication>

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
    QList<QString> cont_nivel ={contra,nivel};


    QFile file("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");
     QFile file2("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    file2.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream escribir(&file2);

    QTextStream datosArchivo(&file);
        while(!datosArchivo.atEnd()){
            datosArchivo>>usu_archivo;

            if(usuario==usu_archivo){
                ban=0;
                QMessageBox::critical(this,"Intente otra vez", "Usuario existente");

            }

        }

            if(ban==1){
                hide();
                QMap<QString,QList<QString>> reg;
                reg[usuario]= cont_nivel;
                escribir<<usuario<<"  "<<contra<<"  "<<nivel<<endl;


                juego= new Juego(this, usuario, contra, nivel);
                //juego.setWindowFlags(Qt::WindowCloseButtonHint);
                juego->show();

            }
            file.close();
            file2.close();


}













