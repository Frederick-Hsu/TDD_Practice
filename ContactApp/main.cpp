#include "PanelContact.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PanelContact w;
    w.show();
    return a.exec();
}
