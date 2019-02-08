#include "rendersegment.h"


RenderSegment::RenderSegment(Segment *s)
{
    initializeOpenGLFunctions();

    lineVBO.create();
    pointVBO.create();

    initializePoint();
    seg = s;

    initializeLines(stride * s->getLength());
}

RenderSegment::~RenderSegment()
{
    lineVBO.destroy();
    pointVBO.destroy();
}

void RenderSegment::addSeg(Segment *s)
{
    seg = s;
}

void RenderSegment::draw(QOpenGLShaderProgram *program, float x, float y)
{
    int position = program->attributeLocation("vertexPosition");
    program->enableAttributeArray(position);
    program->setAttributeBuffer(position, GL_FLOAT, 0, 3, 0);

    QMatrix4x4 model;

    vector<float> n = seg->getNoteValues();

    pointVBO.bind();

    for(int i = 0; i < n.size(); i++)
    {
        model.translate(x + stride * i, y + n[i], -5.0);
        program->setUniformValue("model", model);
        glDrawArrays(GL_POINTS, 0, 1);
        model.setToIdentity();
    }

    lineVBO.bind();

    model.translate(x, y, -5.0f);

    program->setUniformValue("model", model);

    glDrawArrays(GL_LINES, 0, 10);

    model.setToIdentity();
}

float RenderSegment::getStride()
{
    return stride;
}

void RenderSegment::initializePoint()
{
    GLfloat pointVertex[] =
    {
        0.0f, 0.0f, 0.0f
    };

    pointVBO.bind();
    pointVBO.allocate(pointVertex, sizeof (pointVertex));
}

void RenderSegment::initializeLines(float length)
{
    GLfloat lineVertices[] =
    {
        0.0f, 0.0f, 0.0f,
        length, 0.0f, 0.0f,
        0.0f, 0.2f, 0.0f,
        length, 0.2f, 0.0f,
        0.0f, 0.4f, 0.0f,
        length, 0.4f, 0.0f,
        0.0f, 0.6f, 0.0f,
        length, 0.6f, 0.0f,
        0.0f, 0.8f, 0.0f,
        length, 0.8f, 0.0f
    };

    lineVBO.bind();
    lineVBO.allocate(lineVertices, sizeof (lineVertices));
}
