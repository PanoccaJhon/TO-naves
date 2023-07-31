#include "info2.h"
#include "ui_info2.h"

info2::info2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info2)
{
    ui->setupUi(this);
}

info2::~info2()
{
    delete ui;
}
