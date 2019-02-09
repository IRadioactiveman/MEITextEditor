#ifndef RENDERSEGMENT_H
#define RENDERSEGMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
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
    void draw(QOpenGLShaderProgram *program, float x, float y, float *newX, float *newY);
    float getStride();

private:
    QOpenGLBuffer lineVBO;
    QOpenGLBuffer pointVBO;
    Segment *seg;
    Note *previousNote;
    float stride = 0.2f;
    void initializePoint();
    void initializeLines(float length);
    void translateNoteValue(Note *n);

    GLuint glvbo;
};

#else
class renderSegment;
#endif // RENDERSEGMENT_H
