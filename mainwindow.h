#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "carro.h"
#include "jardin.h"
#include "vidas.h"
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

public slots:

    void activartiempo();
private slots:
    void niveles();


private:
    Ui::MainWindow *ui;
             //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;
    Carro *personaje;//scene que muestra los objetos animados
    QTimer *cronometro, *tiempo;

    QList<Vidas *> vidas;
    int contador=0;

    float vel=1;

    int nivel=0;

    Jardin *numero1,*numero2,*numero3,*numero4;

    void keyPressEvent(QKeyEvent *event);
    QList<Vidas*> eliminar(QList<Vidas*>lista,int pos);
};

#endif // MAINWINDOW_H
