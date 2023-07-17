#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "partida.h"
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

