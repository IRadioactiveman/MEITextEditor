#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <iostream>
#include <vector>
#include "rendersegment.h"
#include "segment.h"
using namespace std;

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    RenderWidget(QWidget *parent = nullptr);
    void addSegment(Segment *s);

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    void initializeShaders();

private:
    QOpenGLShaderProgram shader;
    QMatrix4x4 projection;
    vector<Segment*> segments;

};

#endif // RENDERWIDGET_H
