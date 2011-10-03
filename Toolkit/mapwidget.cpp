#include <QMouseEvent>

#include "mapwidget.h"
#include "mainwindow.h"

MapWidget::MapWidget(QWidget *parent, QGLWidget *shareWidget) :
	GLWidget(parent, shareWidget)
{	
	// enable mouse tracking
	setMouseTracking(true);
	// initialize new map
	map = new Map();

	// set mouseinfo defaults
	mouseInfo.x = 0;
	mouseInfo.y = 0;
	mouseInfo.left_down = false;
	mouseInfo.right_down = false;
	mouseInfo.middle_down = false;

	// create new properties window
	propertiesWindow = new PropertiesWindow(0);
	// TODO: display it and handle properties stuff
}

void MapWidget::initializeGL()
{
	GLWidget::initializeGL();

	map->onCreate("New map", "../Resources/tiles.png", 20, 15);
}

void MapWidget::onActive()
{
	// this function is called when the widget comes into view we will simply make sure the resize is correct
	resizeGL(map->getWidth() * 16, map->getHeight() * 16);
}

void MapWidget::resizeGL(int w, int h)
{
	GLWidget::resizeGL(w, h);

	// TODO: possibly create a define that holds the tile size just in case the size changes
	resize(map->getWidth() * 16, map->getHeight() * 16);
}

void MapWidget::paintGL()
{
	GLWidget::paintGL();

	map->onDraw(LayerGround);
	map->onDraw(LayerMiddle);
	map->onDraw(LayerAbove);

	// draw the cursor!
	glDisable(GL_TEXTURE_2D);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(mouseInfo.x + 2, mouseInfo.y + 1);
		glVertex2i(mouseInfo.x + 14, mouseInfo.y + 1);
		glVertex2i(mouseInfo.x + 14, mouseInfo.y + 14);
		glVertex2i(mouseInfo.x + 1, mouseInfo.y + 14);
	}
	glEnd();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(mouseInfo.x + 3, mouseInfo.y + 2);
		glVertex2i(mouseInfo.x + 13, mouseInfo.y + 2);
		glVertex2i(mouseInfo.x + 13, mouseInfo.y + 13);
		glVertex2i(mouseInfo.x + 2, mouseInfo.y + 13);
	}
	glEnd();
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(mouseInfo.x + 4, mouseInfo.y + 3);
		glVertex2i(mouseInfo.x + 12, mouseInfo.y + 3);
		glVertex2i(mouseInfo.x + 12, mouseInfo.y + 12);
		glVertex2i(mouseInfo.x + 3, mouseInfo.y + 12);
	}
	glEnd();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
}

void MapWidget::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		mouseInfo.left_down = true;
	else if (e->button() == Qt::RightButton)
		mouseInfo.right_down = true;
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = true;
}

void MapWidget::mouseMoveEvent(QMouseEvent *e)
{
	mouseInfo.x = e->pos().x() - ( e->pos().x() % 16 );
	mouseInfo.y = e->pos().y() - ( e->pos().y() % 16 );

	updateGL();
}

void MapWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		mouseInfo.left_down = false;
	else if (e->button() == Qt::RightButton)
		mouseInfo.right_down = false;
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = false;
}

Map *MapWidget::getMap()
{
	return map;
}

void MapWidget::clickedSomething()
{

}
