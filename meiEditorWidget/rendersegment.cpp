#include "rendersegment.h"


RenderSegment::RenderSegment()
{
    initializeOpenGLFunctions();

    vbo.create();
    initializeGeometry();
}

RenderSegment::~RenderSegment()
{
    vbo.destroy();
}

void RenderSegment::addSeg(Segment *s)
{
    seg = s;
}

void RenderSegment::draw(QOpenGLShaderProgram *program)
{
    vbo.bind();

    int position = program->attributeLocation("vertexPosition");
    program->enableAttributeArray(position);
    program->setAttributeBuffer(position, GL_FLOAT, 0, 3, 0);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(float) * 18);
}

void RenderSegment::initializeGeometry()
{
    float vertices[] =
    {
        -1.0, -1.0, 0.0,
        -1.0, 1.0, 0.0,
        1.0, 1.0, 0.0,
        1.0, 1.0, 0.0,
        -1.0, -1.0, 0.0,
        1.0, -1.0, 0.0
    };

    vbo.bind();
    vbo.allocate(vertices, 18 * sizeof (float));
}
