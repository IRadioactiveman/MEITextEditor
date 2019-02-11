#define _CRT_SECURE_NO_DEPRECATE
#include "renderwidget.h"

RenderWidget::RenderWidget(QWidget *parent) :QOpenGLWidget (parent)
{

}

RenderWidget::~RenderWidget()
{

}

void RenderWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);

    initializeShaders();

    texture = new QOpenGLTexture(QImage(":/font.bmp"));
    texture->setMinificationFilter(QOpenGLTexture::Linear);
    texture->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
}

void RenderWidget::resizeGL(int width, int height)
{
    qreal ratio = qreal(width) / qreal(height ? height : 1);
    const qreal zNear = 0.1, zFar = 1000.0, fov = 45.0;

    projection.setToIdentity();
    projection.perspective(fov, ratio, zNear, zFar);

    startX = -4.0f;
    startY = 1.0f;
}

void RenderWidget::paintGL()
{
    startX = -4.0f;
    startY = initY;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.bind();
    shader.setUniformValue("projection", projection);
    shader.setUniformValue("pointSize", 10.0f);

    /*
    textShader.bind();
    textShader.setUniformValue("projection", projection);
    */

    for(int i = 0; i < segments.size(); i++)
    {
        RenderSegment *seg = new RenderSegment(segments[i]);

        seg->draw(&shader, &textShader, texture, startX, startY, &startX, &startY);

        delete seg;
    }
}

void RenderWidget::initializeShaders()
{
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

    if(!textShader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/textVertexShader.glsl"))
    {
        cout << textShader.log().toStdString();
    }

    if(!textShader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/textFragmentShader.glsl"))
    {
        cout << textShader.log().toStdString();
    }

    if(textShader.link())
    {
        cout << textShader.log().toStdString();
    }
}

void RenderWidget::addSegment(Segment *s)
{
    segments.push_back(s);
    currentSegment = segments[segments.size()-1];
}

void RenderWidget::increaseInitY()
{
    initY += 0.1;
}

void RenderWidget::decreaseInitY()
{
    initY -= 0.1;
}

GLuint RenderWidget::loadBMP(const char * imagepath){

    printf("Reading image %s\n", imagepath);


    // Data read from the header of the BMP file
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int imageSize;
    unsigned int width, height;
    // Actual RGB data
    unsigned char * data;

    fflush(stdout);

    // Open the file
    FILE * file = fopen(imagepath,"rb");

    if (!file){
        printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", imagepath);
        getchar();

        return 0;
    }

    fflush(stdout);

    // Read the header, i.e. the 54 first bytes

    // If less than 54 bytes are read, problem
    if ( fread(header, 1, 54, file)!=54 ){
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }
    // A BMP files always begins with "BM"
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }
    // Make sure this is a 24bpp file
    if ( *(int*)&(header[0x1E])!=0  )         {printf("Not a correct BMP file\n");    fclose(file); return 0;}
    if ( *(int*)&(header[0x1C])!=24 )         {printf("Not a correct BMP file\n");    fclose(file); return 0;}

    // Read the information about the image
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way

    // Create a buffer
    data = new unsigned char [imageSize];

    // Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);

    // Everything is in memory now, the file can be closed.
    fclose (file);

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    // OpenGL has now copied the data. Free our own version
    delete [] data;

    // Poor filtering, or ...
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Return the ID of the texture we just created
    return textureID;
}
