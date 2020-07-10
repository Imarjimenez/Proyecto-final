#ifndef TIEMPO_H
#define TIEMPO_H

#include <QThread>
class Tiempo : public QThread
{
    Q_OBJECT
public:
    Tiempo(int segundos, QObject *parent = nullptr);
signals:
    void timeOut();
protected:
    void run() override;
private:
    int mSegundos;
};

#endif // TIEMPO_H
