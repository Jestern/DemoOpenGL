#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLFunctions_4_5_Core>
#include <QFile>
#include <QByteArray>

#include <QDebug>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core {
public:
    // TODO buscar que es explicit
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    GLuint shader_programme;
    GLuint vao;
    QMatrix4x4 translate;

};

#endif // GLWIDGET_H
