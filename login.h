#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <juego.h>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QMap>

#include <QMessageBox>

namespace Ui {

class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString contra_archivo;
    QString usu_archivo;
    QString niv_archivo;


private slots:
    void on_pushButton_2_clicked();

private:


    Ui::Login *ui;
    QGraphicsScene *scene;
    QString nivel;
    Juego *juego;
    int ban=1;









};

#endif // LOGIN_H
