#ifndef TILESETWINDOW_H
#define TILESETWINDOW_H

#include "glwidget.h"

#include "Graphics.h"

class TilesetWindow : public GLWidget
{
    Q_OBJECT

	// a struct to hold info about the mouse
	struct MouseInfo
	{
		int x;
		int y;
		bool left_down;
		bool right_down;
		bool middle_down;
	};

public:
    explicit TilesetWindow(QWidget *parent = 0, QGLWidget *shareWidget = 0);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
	Sprite *tileset;
	MouseInfo mouseInfo;
	Rectangle selection;
};

#endif // TILESETWINDOW_H
