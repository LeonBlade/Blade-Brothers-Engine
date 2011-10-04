#include <QMouseEvent>

#include "mapwidget.h"
#include "mainwindow.h"
#include "tileselection.h"

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

	glEnable(GL_TEXTURE_2D);

	map->onDraw(LayerGround);
	map->onDraw(LayerMiddle);
	map->onDraw(LayerAbove);

	// draw selection
	if (mouseInfo.right_down)
		TileSelection::drawSelection(selection.x, selection.y, false);
	else
		TileSelection::drawSelection(mouseInfo.x, mouseInfo.y, true);
}

void MapWidget::drawTiles()
{
	int w = (TileSelection::getSelection().w - TileSelection::getSelection().x) / 16;
	int h = (TileSelection::getSelection().h - TileSelection::getSelection().y) / 16;

	for (int i = 0; i < w * h; i++)
	{
		int cx = i % w;
		int cy = (((w - (i % w)) + i) / w) - 1;
		int tile = TileSelection::getTiles()[cx + (w * cy)];
		map->setTile(cx + mouseInfo.x / 16, cy + mouseInfo.y / 16, tile, LayerMiddle);
	}
}

void MapWidget::mousePressEvent(QMouseEvent *e)
{
	mouseInfo.x = e->pos().x() - ( e->pos().x() % 16 );
	mouseInfo.y = e->pos().y() - ( e->pos().y() % 16 );

	if (mouseInfo.x < 0)
		mouseInfo.x = 0;
	else if (mouseInfo.x > map->getWidth() * 16)
		mouseInfo.x = map->getWidth() * 16 - 16;
	if (mouseInfo.y < 0)
		mouseInfo.y = 0;
	else if (mouseInfo.y > map->getHeight() * 16)
		mouseInfo.y = map->getHeight() * 16 - 16;

	if (e->button() == Qt::LeftButton)
	{
		mouseInfo.left_down = true;
		drawTiles();
	}
	else if (e->button() == Qt::RightButton)
	{
		mouseInfo.right_down = true;
		selection.x = mouseInfo.x;
		selection.y = mouseInfo.y;
		selection.w = mouseInfo.x + 16;
		selection.h = mouseInfo.y + 16;
		TileSelection::setSelection(selection);
		emit changedSelection(selection);
	}
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = true;
}

void MapWidget::mouseMoveEvent(QMouseEvent *e)
{
	mouseInfo.x = e->pos().x() - ( e->pos().x() % 16 );
	mouseInfo.y = e->pos().y() - ( e->pos().y() % 16 );

	if (mouseInfo.x < 0)
		mouseInfo.x = 0;
	else if (mouseInfo.x > map->getWidth() * 16)
		mouseInfo.x = map->getWidth() * 16 - 16;
	if (mouseInfo.y < 0)
		mouseInfo.y = 0;
	else if (mouseInfo.y > map->getHeight() * 16)
		mouseInfo.y = map->getHeight() * 16 - 16;

	if (mouseInfo.left_down)
		drawTiles();

	if (mouseInfo.right_down)
	{
		selection.w = mouseInfo.x;
		selection.h = mouseInfo.y;
		if (selection.w >= selection.x)
			selection.w += 16;
		if (selection.h >= selection.y)
			selection.h += 16;
		TileSelection::setSelection(selection);
		emit changedSelection(selection);
	}

	updateGL();
}

void MapWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		mouseInfo.left_down = false;
	else if (e->button() == Qt::RightButton)
	{
		if (mouseInfo.right_down)
		{
			int sx = 0;
			int sy = 0;
			for (int y = selection.y / 16; y < selection.h / 16; y++)
			{
				for (int x = selection.x / 16; x < selection.w / 16; x++)
				{
					int tile = map->getTile(x, y, LayerMiddle);
					TileSelection::setTile(sx, sy, tile);
					sx++;
				}
				sx = 0;
				sy++;
			}
			emit changedSelection(selection);
		}
		mouseInfo.right_down = false;
	}
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = false;
}

Map *MapWidget::getMap()
{
	return map;
}
