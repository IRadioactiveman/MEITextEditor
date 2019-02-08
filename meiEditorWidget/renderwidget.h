#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "rendersegment.h"
#include "segment.h"
using namespace std;

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    RenderWidget(QWidget *parent = nullptr);
    void addSegment(Segment *s);
    Segment *currentSegment;

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    void initializeShaders();
    GLuint loadShader(const char* v, const char* f);

private:
    QOpenGLShaderProgram shader;
    QMatrix4x4 projection;
    vector<Segment*> segments;
    float currentLength;
    float startX;
    float startY = 1.0f;
    GLuint glshader;

};

#endif // RENDERWIDGET_H
