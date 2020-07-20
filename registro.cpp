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

    QFile file("C:/Users/user/Documents/Parking_simulator/Registro/registro.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QTextStream datosArchivo(&file);
        datosArchivo<<usuario<<"  "<<contra<<endl;
    }
    file.close();

}
