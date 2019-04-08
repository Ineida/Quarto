#ifndef QUARTO_H
#define QUARTO_H

#include <QMainWindow>

namespace Ui {
class Quarto;
}

class Quarto : public QMainWindow
{
    Q_OBJECT

public:
    explicit Quarto(QWidget *parent = nullptr);
    ~Quarto();

private:
    Ui::Quarto *ui;
};

#endif // QUARTO_H
