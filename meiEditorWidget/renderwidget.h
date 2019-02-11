#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
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
    ~RenderWidget();
    void addSegment(Segment *s);
    void increaseInitY();
    void decreaseInitY();
    Segment *currentSegment;

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    void initializeShaders();
    GLuint loadBMP(const char * imagepath);
    GLuint loadShader(const char* v, const char* f);

private:
    QOpenGLShaderProgram shader;
    QOpenGLShaderProgram textShader;
    QOpenGLTexture *texture;
    GLuint textureID;
    QMatrix4x4 projection;
    vector<Segment*> segments;
    float currentLength;
    float startX;
    float startY;
    float initY = 1.0f;

};

#endif // RENDERWIDGET_H
