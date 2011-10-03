#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include "glwidget.h"
#include "propertieswindow.h"

#include "Map.h"

class MapWidget : public GLWidget
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
	MapWidget(QWidget *parent = 0, QGLWidget *shareWidget = 0);

    void initializeGL();
	void onActive();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

	Map *getMap();

public slots:
	void clickedSomething();

private:
	PropertiesWindow *propertiesWindow;
	Map *map;
	MouseInfo mouseInfo;
};

#endif // MAPWINDOW_H
