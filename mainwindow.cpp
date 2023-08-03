#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "partida.h"
#include "puntuacion.h"
#include "qapplication.h"
#include <QScreen>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnExit_clicked()
{
    close();
}


void MainWindow::on_btnNewGame_clicked()
{
    Partida nuevaPartida;
    nuevaPartida.configurar();
    this->setVisible(false);
    int puntaje = nuevaPartida.enJuego();
    this->setVisible(true);

}
void MainWindow::on_btnOptions_clicked()
{
    puntuacion *i = new puntuacion(0);
    i->show();

}
