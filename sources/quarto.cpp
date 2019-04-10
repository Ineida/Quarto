#include "Header/quarto.h"
#include "ui_quarto.h"

Quarto::Quarto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Quarto)
{
    ui->setupUi(this);
}

Quarto::~Quarto()
{
    delete ui;
}
