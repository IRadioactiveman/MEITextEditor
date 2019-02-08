#ifndef RENDERSEGMENT_H
#define RENDERSEGMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "segment.h"
using namespace std;

class RenderSegment :protected QOpenGLFunctions
{
public:
    RenderSegment(Segment *s);
    ~RenderSegment();
    void addSeg(Segment *s);
    void draw(QOpenGLShaderProgram *program, float x, float y);
    float getStride();

private:
    QOpenGLBuffer lineVBO;
    QOpenGLBuffer pointVBO;
    Segment *seg;
    float stride = 0.2f;
    void initializePoint();
    void initializeLines(float length);

    GLuint glvbo;
};

#else
class renderSegment;
#endif // RENDERSEGMENT_H
