#include "renderwidget.h"

RenderWidget::RenderWidget(QWidget *parent) :QOpenGLWidget (parent)
{

}

void RenderWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    initializeShaders();

}

void RenderWidget::resizeGL(int width, int height)
{
    qreal ratio = qreal(width) / qreal(height ? height : 1);
    const qreal zNear = 0.5, zFar = 1000.0, fov = 45.0;

    projection.setToIdentity();
    projection.perspective(fov, ratio, zNear, zFar);
}

void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 model;
    model.translate(0.0, 0.0, 0.0);

    QMatrix4x4 view;
    view.lookAt(QVector3D(4,4,4),
                QVector3D(0,0,0),
                QVector3D(0,1,0));

    shader.setUniformValue("MVP", projection * view * model);

    for(int i = 0; i < segments.size(); i++)
    {
        RenderSegment *seg = new RenderSegment();
        seg->addSeg(segments[i]);
        seg->draw(&shader);
        delete seg;
    }

}

void RenderWidget::initializeShaders()
{

    cout << "YIAAAH\n";

    if(!shader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/simpleVertexShader.glsl"))
    {
        cout << shader.log().toStdString();
    }

    if(!shader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/simpleFragmentShader.glsl"))
    {
        cout << shader.log().toStdString();
    }

    if(shader.link())
    {
        cout << shader.log().toStdString();
    }
    shader.bind();
}

void RenderWidget::addSegment(Segment *s)
{
    segments.push_back(s);
}
