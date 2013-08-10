#include "widget.h"
#include "ui_widget.h"
#include <GL/glu.h>
#include <cmath>
#include <QDebug>
#include <QGLBuffer>

Widget::Widget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(100,100,640,480);
    f5.start(0);
    f4.start(1000);
    connect(&f5,SIGNAL(timeout()),this,SLOT(updateGL()));
    connect(&f4,SIGNAL(timeout()),this,SLOT(printFps()));
    sfps=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::printFps() {
    static int pre=0;
    qDebug()<<sfps-pre<<endl;
    pre=sfps;
}

void Widget::initializeGL() {
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnableClientState(GL_VERTEX_ARRAY);
    //glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );


}

void Widget::paintGL() {
    double fps=sfps++ *.1;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-6);

    buffer=new QGLBuffer(QGLBuffer::VertexBuffer);
    buffer->create();
    buffer->bind();

    GLfloat data[]={
        0.0f, 0.0f, -10.0f,
        0.0f, -1.0f, -10.0f,
        -1.0f, -1.0f, -10.0f
    };
    buffer->allocate(data,sizeof(GLfloat)*9);


    glVertexPointer(3,GL_FLOAT,0,0);
    glColor3f(1,1,1);
    glDrawArrays(GL_LINE_LOOP,0,3);

    glBegin(GL_TRIANGLES);{
        glColor3f(0.5+sin(fps)*.5,0,0);
        glVertex3f(0,0,0);
        glColor3f(0.5+sin(fps*.9)*.5,0.5+sin(fps*.8)*.5,0);
        glVertex3f(1,0,0);
        glColor3f(0.5+sin(fps*.7)*.5,0.5+sin(fps*.6)*.5,0.5+sin(fps*2)*.5);
        glVertex3f(1,1,0);
    } glEnd();
}

void Widget::resizeGL(int width, int height) {
    if (!height) height=1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);
}
