
#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <juego.h>
#include <QGraphicsScene>
#include <QFile>
#include <QList>
#include <QMap>
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

    Juego *juego;
    int ban=1;


    QString usu_archivo;

};

#endif // REGISTRO_H
