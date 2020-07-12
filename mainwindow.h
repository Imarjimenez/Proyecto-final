#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "carro.h"
#include <QKeyEvent>
#include <QImage>
#include <QMessageBox>
#include <QLCDNumber>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();




private:
    Ui::MainWindow *ui;
             //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;
    Carro *personaje;//scene que muestra los objetos animados


    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
