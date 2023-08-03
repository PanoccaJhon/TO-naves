#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <QWidget>

namespace Ui {
class puntuacion;
}

class puntuacion : public QWidget
{
    Q_OBJECT

public:
    explicit puntuacion(QWidget *parent = nullptr);
    ~puntuacion();

private:
    Ui::puntuacion *ui;
};

#endif // PUNTUACION_H
