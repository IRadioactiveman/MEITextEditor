#include "renderwidget.h"

RenderWidget::RenderWidget(QWidget *parent) :QOpenGLWidget (parent)
{

}

void RenderWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);

    initializeShaders();

    glshader = loadShader("C:\\Users\\Gott\\Documents\\GitHub\\MEITextEditor\\meiEditorWidget\\simpleVertexShader.glsl", "C:\\Users\\Gott\\Documents\\GitHub\\MEITextEditor\\meiEditorWidget\\simpleFragmentShader.glsl");
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.setUniformValue("projection", projection);
    shader.setUniformValue("pointSize", 10.0f);

    for(int i = 0; i < segments.size(); i++)
    {
        RenderSegment *seg = new RenderSegment(segments[i]);

        seg->draw(&shader, startX, startY);

        startX += segments[i]->getLength() * seg->getStride();

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
    shader.bind();
}

GLuint RenderWidget::loadShader(const char * vertex_file_path, const char * fragment_file_path)
{

    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    string VertexShaderCode;
    ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if (VertexShaderStream.is_open()) {
        stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }
    else {
        cout << "Impossible to open " << vertex_file_path << ". Are you in the right directory ? Don't forget to read the FAQ !\n";
        cout.flush();
        getchar();
        return 0;
    }

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;


    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }



    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }



    // Link the program
    printf("Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }


    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

void RenderWidget::addSegment(Segment *s)
{
    segments.push_back(s);
    currentSegment = segments[segments.size()-1];
}
