#include "Header/quarto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Quarto w;
    w.show();

    return a.exec();
}
