#include "myglwidget.h"
#include <QOpenGLExtraFunctions>

MyGLWidget::MyGLWidget(QWidget *parent){};

const string vertexShader =
"#version 330\n"
"uniform mat4 Model;"
"uniform mat4 Projection;"
"uniform mat4 View;"
"layout(location = 0)in vec3 position;"
"layout(location = 1)in vec2 texCoord;"
"void main()"
"{"
"	gl_Position = Projection * View * Model * vec4(position, 1.0);"
"}";

const string fragmentShader =
"#version 330\n"
"out vec4 ColorOut;"
"void main()"
"{"
"   ColorOut = vec4(0.0, 0.0, 0.0, 0.0);"
"}";

static const GLfloat shapeToDraw[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    createShaderProgram();

    view = lookAt(
                vec3(0.0f, 0.0f, -5),
                vec3(0.0f),
                vec3(0.0f, 1.0f, 0.0f)
                );
}

void MyGLWidget::resizeGL(int width, int height)
{
    projection = mat4(1.0f);
    projection = perspective(radians(45.0f), (float)(this->width()) / (float)(this->height()), 0.1f, 100.0f);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProgram);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shapeToDraw), shapeToDraw, GL_STATIC_DRAW);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,  "View"), 1, GL_FALSE, &view[0][0]);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,  "Projection"), 1, GL_FALSE, &projection[0][0]);

    GLuint position = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(position);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glVertexAttribPointer(
    position,          // must match shader
    3,                  // size, number of vertices
    GL_FLOAT,           // type
    GL_FALSE,           // normalized?
    0,                  // stride, data between vertices, e.g. attributes
    (void*)0            // array buffer offset in the beginning
    );

    glDrawArrays(GL_TRIANGLES, 0, sizeof (float) * 9);

    glDisableVertexAttribArray(position);


}

void MyGLWidget::compileShader(GLuint shader, string source)
{
    GLint result = GL_FALSE;
    int logLength;

    auto _source = source.c_str();

    glShaderSource(shader, 1, &_source, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    vector<GLchar> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(shader, logLength, NULL, &vertShaderError[0]);
    auto error = string(&vertShaderError[0]);
    if (!error.empty())
        cout << error << endl;
}

void MyGLWidget::createShaderProgram()
{
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    compileShader(vertShader, vertexShader);

    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    compileShader(fragShader, fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
}
