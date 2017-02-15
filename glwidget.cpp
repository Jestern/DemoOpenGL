#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
}

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    qDebug() << reinterpret_cast< char const * >(glGetString(GL_VERSION));
}

void GLWidget::resizeGL(int w, int h) {
}

void GLWidget::paintGL() {

}
