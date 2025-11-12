
#include <QApplication>
#include <QStyleFactory>

#include "MainWindow.hpp"



int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    app.setStyle(QStyleFactory::create("Fusion"));

    MainWindow mw;

    mw.show();

    return app.exec();
}
