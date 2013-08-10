#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qgl.h>
#include <QGLWidget>
#include <QTimer>
#include <QGLBuffer>

namespace Ui {
class Widget;
}

class Widget : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
  void initializeGL();
  void paintGL();
  void resizeGL( int width, int height );

public slots:
  void printFps();

private:
    Ui::Widget *ui;
    QTimer f5,f4;
    int sfps;
    QGLBuffer *buffer;
};

#endif // WIDGET_H
