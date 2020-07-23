#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <juego.h>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>

namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registro *ui;
    QGraphicsScene *scene;
    QString nivel;
    Juego *juego;
    bool registro=false;

    QString usu_archivo;

};

#endif // REGISTRO_H
