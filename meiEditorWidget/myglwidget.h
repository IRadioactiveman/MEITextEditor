#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <vector>
#include <string>
#include <iostream>
#include "rendersegment.h"
#include "GLM/glm/glm.hpp"
#include "GLM/glm/gtc/matrix_transform.hpp"
using namespace std;
using namespace glm;

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    MyGLWidget(QWidget *parent = 0);

private:
    GLuint shaderProgram;
    vector<RenderSegment> segments;
    mat4 view;
    mat4 projection;
    void compileShader(GLuint shader, string source);
    void createShaderProgram();

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
};

#else
class MyGLWidget;
#endif // MYGLWIDGET_H
