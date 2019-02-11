#include "rendersegment.h"


RenderSegment::RenderSegment(Segment *s)
{
    initializeOpenGLFunctions();

    lineVBO.create();
    pointVBO.create();

    //textVertexVBO.create();
    //textUvVBO.create();

    initializePoint();
    seg = s;

    initializeLines(stride);
}

RenderSegment::~RenderSegment()
{
    lineVBO.destroy();
    pointVBO.destroy();

    //textVertexVBO.destroy();
    //textUvVBO.destroy();
}

void RenderSegment::addSeg(Segment *s)
{
    seg = s;
}

void RenderSegment::renderText(const char *text, float x, float y, int size, QOpenGLShaderProgram *program, QOpenGLTexture *texture)
{
    unsigned int length = strlen(text);

    vector<QVector3D> vertices;
    vector<QVector2D> uvs;

    for(unsigned int i = 0; i < length; i++)
    {
        QVector3D vertexUL = QVector3D(x+i*size , y+size, 0.0f);
        QVector3D vertexUR = QVector3D(x+i*size+size , y+size, 0.0f);
        QVector3D vertexDL = QVector3D(x+i*size+size , y, 0.0f);
        QVector3D vertexDR = QVector3D(x+i*size , y, 0.0f);

        vertices.push_back(vertexUL);
        vertices.push_back(vertexDL);
        vertices.push_back(vertexUR);

        vertices.push_back(vertexDR);
        vertices.push_back(vertexUR);
        vertices.push_back(vertexDL);

        char character = text[i];

        float uvX = (character%16)/16.0f;
        float uvY = (character/16)/16.0f;

        QVector2D uvUL = QVector2D(uvX, uvY);
        QVector2D uvUR = QVector2D(uvX+1.0f/16.0f, uvY);
        QVector2D uvDL = QVector2D(uvX+1.0f/16.0f, (uvY+1.0f/16.0f));
        QVector2D uvDR = QVector2D(uvX, (uvY+1.0f/16.0f));

        uvs.push_back(uvUL);
        uvs.push_back(uvDL);
        uvs.push_back(uvUR);

        uvs.push_back(uvDR);
        uvs.push_back(uvUR);
        uvs.push_back(uvDL);
    }

    textVertexVBO.bind();
    textVertexVBO.allocate(&vertices, vertices.size() * sizeof (QVector3D));

    textUvVBO.bind();
    textUvVBO.allocate(&uvs, uvs.size() * sizeof (QVector2D));

    program->bind();

    glActiveTexture(GL_TEXTURE0);

    texture->bind();

    program->setUniformValue("myTextureSampler", 0);

    int position = program->attributeLocation("vertexPosition");
    program->enableAttributeArray(position);
    program->setAttributeBuffer(position, GL_FLOAT, 0, 3, 0);

    int uv = program->attributeLocation("vertexUv");
    program->enableAttributeArray(uv);
    program->setAttributeBuffer(uv, GL_FLOAT, 0, 2, 0);

    QMatrix4x4 model;
    model.translate(x, y, -5.0f);
    program->setUniformValue("model", model);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glDisable(GL_BLEND);

    program->disableAttributeArray(position);
    program->disableAttributeArray(uv);

    program->release();
    textVertexVBO.release();
    textUvVBO.release();
}

void RenderSegment::draw(QOpenGLShaderProgram *program, QOpenGLShaderProgram *textProgram, QOpenGLTexture *texture, float x, float y, float *newX, float *newY)
{   
    //renderText(seg->getSyllable().c_str(), x, y, 20, textProgram, texture);

    program->bind();

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

        model.translate(x + stride * i + xOffset, y + yOffset, -5.0f);
        program->setUniformValue("model", model);
        glDrawArrays(GL_LINES, 0, 10);
        model.setToIdentity();

        translateNoteValue(n[i]);

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

        previousNote = n[i];
    }

    model.translate(x, y + 0.8f, -5.0f);
    program->setUniformValue("model", model);
    program->setUniformValue("color", QVector3D(1.0, 0.0, 1.0));
    glDrawArrays(GL_POINTS, 0, 1);
    program->setUniformValue("color", QVector3D(0.0, 0.0, 0.0));
    model.setToIdentity();

    program->disableAttributeArray(position);

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
