#include "rendersegment.h"


RenderSegment::RenderSegment(Segment *s)
{
    initializeOpenGLFunctions();

    lineVBO.create();
    pointVBO.create();

    initializePoint();
    seg = s;

    initializeLines(stride);
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

void RenderSegment::draw(QOpenGLShaderProgram *program, float x, float y, float *newX, float *newY)
{
    int position = program->attributeLocation("vertexPosition");
    program->enableAttributeArray(position);
    program->setAttributeBuffer(position, GL_FLOAT, 0, 3, 0);

    QMatrix4x4 model;

    vector<Note*> n = seg->getNotes();

    float xOffset = 0;
    float yOffset = 0;
    int counter = 0;
    int i;
    previousNote = new Note();
    translateNoteValue(previousNote);

    for(i = 0; i < n.size(); i++)
    {
        if(x + stride * i >= counter * 8.0f + 4.0f)
        {
            xOffset += -8.0f;
            yOffset += -1.5f;

            counter++;
        }

        translateNoteValue(n[i]);

        pointVBO.bind();
        if(n[i]->getPitch().compare("undefined") == 0)
        {
            program->setUniformValue("color", QVector3D(1.0, 0.0, 0.0));

            if(previousNote && !n[i]->getRelation().empty())
            {
                if(n[i]->getRelation().compare("s") == 0)
                {
                    n[i]->currentPosition = previousNote->currentPosition;
                }
                if(n[i]->getRelation().compare("d") == 0)
                {
                    n[i]->currentPosition = previousNote->currentPosition - 0.1f;
                }
                if(n[i]->getRelation().compare("u") == 0)
                {
                    n[i]->currentPosition = previousNote->currentPosition + 0.1f;
                }
                else{}
            }
        }

        model.translate(x + stride * i + xOffset + 0.05f, y + n[i]->currentPosition + yOffset, -5.0);
        program->setUniformValue("model", model);
        glDrawArrays(GL_POINTS, 0, 1);
        program->setUniformValue("color", QVector3D(0.0, 0.0, 0.0));
        model.setToIdentity();

        lineVBO.bind();
        model.translate(x + stride * i + xOffset, y + yOffset, -5.0f);
        program->setUniformValue("model", model);
        glDrawArrays(GL_LINES, 0, 10);
        model.setToIdentity();

        previousNote = n[i];
    }

    *newX = x + stride * i + xOffset;
    *newY = y + yOffset;
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

void RenderSegment::translateNoteValue(Note *n)
{
    if(n->getPitch().compare("c") == 0)
    {
        n->currentPosition = -0.2f;
        //return -0.2f;
    }
    if(n->getPitch().compare("d") == 0)
    {
        n->currentPosition = -0.1f;
        //return -0.1f;
    }
    if(n->getPitch().compare("e") == 0)
    {
        n->currentPosition = 0.0f;
        //return 0.0f;
    }
    if(n->getPitch().compare("f") == 0)
    {
        n->currentPosition = 0.1f;
        //return 0.1f;
    }
    if(n->getPitch().compare("g") == 0)
    {
        n->currentPosition = 0.2f;
        //return 0.2f;
    }
    if(n->getPitch().compare("a") == 0)
    {
        n->currentPosition = 0.3f;
        //return 0.3f;
    }
    if(n->getPitch().compare("h") == 0)
    {
        n->currentPosition = 0.4f;
        //return 0.4f;
    }
    if(n->getPitch().compare("undefined") == 0)
    {
        n->currentPosition = 0.5f;
        //return 0.5f;
    }
}
