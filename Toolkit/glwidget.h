#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include "Map.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0, QGLWidget *shareWidget = 0);
	~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void keyPressEvent(QKeyEvent *e);
};

#endif // GLWIDGET_H
