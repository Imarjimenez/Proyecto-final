#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene2= new QGraphicsScene;
    ui->graphicsView->setScene(scene);
   // ui->graphicsView_2->setScene(scene2);

    scene->setSceneRect(0,0,1000,420);
    scene->setBackgroundBrush(QPixmap(":/Photos/menu.jpg"));




}

MainWindow::~MainWindow()
{

    delete scene;
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    hide();
    registro= new Registro(this);
    registro->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    login= new Login(this);
    login->show();
}
