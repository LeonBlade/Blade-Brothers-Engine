#ifndef TILESETWINDOW_H
#define TILESETWINDOW_H

#include "glwidget.h"

#include "Graphics.h"

class TilesetWindow : public GLWidget
{
    Q_OBJECT
public:
    explicit TilesetWindow(QWidget *parent = 0, QGLWidget *shareWidget = 0);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
	Sprite *tileset;
};

#endif // TILESETWINDOW_H
