#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
}

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();
    qDebug() << reinterpret_cast< char const * >(glGetString(GL_VERSION));

    GLfloat points[] = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    GLuint vbo = 0;
    glGenBuffers(1, &vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    this->vao = 0;
    glGenVertexArrays (1, &this->vao);
    glBindVertexArray (this->vao);
    glEnableVertexAttribArray (0);
    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    const char* vertex_shader =
    "#version 450\n"
    "in vec3 vp;"
    "void main () {"
    " gl_Position = vec4 (vp, 1.0);"
    "}";

    const char* fragment_shader =
    "#version 450\n"
    "out vec4 frag_colour;"
    "void main () {"
    " frag_colour = vec4 (1.0, 0.0, 0.0, 1.0);"
    "}";

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
}

void GLWidget::paintGL() {

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram (shader_programme);
    glBindVertexArray (vao);
    glDrawArrays (GL_TRIANGLES, 0, 3);




}
