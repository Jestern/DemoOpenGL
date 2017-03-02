#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
}

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();

    glEnable (GL_CULL_FACE); // cull face
    glCullFace (GL_BACK); // cull back face
    glFrontFace (GL_CCW); // GL_CCW for counter clock-wise

    this->translate.translate(0.5f, 0.0f, 0.0f);

    qDebug() << reinterpret_cast< char const * >(glGetString(GL_VERSION));

    GLfloat points[] = {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f

    };

    GLfloat colours[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };



    GLuint points_vbo = 0;
    glGenBuffers(1, &points_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    GLuint colours_vbo = 0;
    glGenBuffers (1, &colours_vbo);
    glBindBuffer (GL_ARRAY_BUFFER, colours_vbo);
    glBufferData (GL_ARRAY_BUFFER, sizeof (colours), colours, GL_STATIC_DRAW);


    this->vao = 0;
    glGenVertexArrays (1, &this->vao);
    glBindVertexArray (this->vao);
    glBindBuffer (GL_ARRAY_BUFFER, points_vbo);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer (GL_ARRAY_BUFFER, colours_vbo);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 0, NULL);



    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    QFile vertexShaderFile(":/shaders/triangle.vert");
    QFile fragmentShaderFile(":/shaders/triangle.frag");

    vertexShaderFile.open(QFile::ReadOnly);
    fragmentShaderFile.open(QFile::ReadOnly);

    const QByteArray vertexShaderSource = vertexShaderFile.readAll();
    const QByteArray fragmentShaderSource = fragmentShaderFile.readAll();

    const char* vertex_shader = vertexShaderSource.constData();

    const char* fragment_shader = fragmentShaderSource.constData();

    GLuint vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vs, 1, &vertex_shader, NULL);
    glCompileShader (vs);
    GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs, 1, &fragment_shader, NULL);
    glCompileShader (fs);


    this->shader_programme = glCreateProgram ();
    glAttachShader (this->shader_programme, fs);
    glAttachShader (this->shader_programme, vs);
    glLinkProgram (this->shader_programme);

}

void GLWidget::resizeGL(int w, int h) {

    glViewport(0, 0, w, h);

}

void GLWidget::paintGL() {

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int matrix_location = glGetUniformLocation (shader_programme, "matrix");
    glUseProgram (shader_programme);
    glUniformMatrix4fv (matrix_location, 1, GL_FALSE, this->translate.data());
    glBindVertexArray (vao);
    glDrawArrays (GL_TRIANGLES, 0, 3);


}
