#include "windowview.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[]) {



    QApplication a(argc, argv);

    // Establecer la versión de opengl a la 4.5
    QSurfaceFormat format;
    format.setVersion(4, 5);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    QSurfaceFormat::setDefaultFormat(format);

    WindowView w;
    w.show();

    return a.exec();
}
