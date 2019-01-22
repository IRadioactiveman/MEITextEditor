#ifndef RENDERSEGMENT_H
#define RENDERSEGMENT_H

#include <vector>
#include <string>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "segment.h"
using namespace std;

class RenderSegment :protected QOpenGLFunctions
{
public:
    RenderSegment();
    ~RenderSegment();
    void addSeg(Segment *s);
    void draw(QOpenGLShaderProgram *program);

private:
    float start;
    float length;
    QOpenGLBuffer vbo;
    Segment *seg;
    void initializeGeometry();
};

#else
class renderSegment;
#endif // RENDERSEGMENT_H
