#ifndef RENDERSEGMENT_H
#define RENDERSEGMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include "segment.h"
using namespace std;

class RenderSegment :protected QOpenGLFunctions
{
public:
    RenderSegment(Segment *s);
    ~RenderSegment();
    void addSeg(Segment *s);
    void renderText(const char *text, float x, float y, int size, QOpenGLShaderProgram *program, QOpenGLTexture *texture);
    void draw(QOpenGLShaderProgram *program, QOpenGLShaderProgram *textProgram, QOpenGLTexture *texture, float x, float y, float *newX, float *newY);
    float getStride();

private:
    QOpenGLBuffer lineVBO;
    QOpenGLBuffer pointVBO;
    QOpenGLBuffer idVBO;
    QOpenGLBuffer textVertexVBO;
    QOpenGLBuffer textUvVBO;
    Segment *seg;
    Note *previousNote;
    float stride = 0.2f;
    void initializePoint();
    void initializeLines(float length);
    void initializeID();
    void translateNoteValue(Note *n);
};

#else
class renderSegment;
#endif // RENDERSEGMENT_H
