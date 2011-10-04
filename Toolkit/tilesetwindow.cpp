#include <QMouseEvent>

#include "tilesetwindow.h"
#include "tileselection.h"

TilesetWindow::TilesetWindow(QWidget *parent, QGLWidget *shareWidget) :
    GLWidget(parent, shareWidget)
{
	tileset = new Sprite();
	setMouseTracking(true);

	// set mouseinfo defaults
	mouseInfo.x = 0;
	mouseInfo.y = 0;
	mouseInfo.left_down = false;
	mouseInfo.right_down = false;
	mouseInfo.middle_down = false;

	selection = (Rectangle){ 0, 0, 16, 16 };
	// update global selection
	TileSelection::setSelection(selection);
}

void TilesetWindow::initializeGL()
{
    GLWidget::initializeGL();

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	tileset = Graphics::addTexture("../Resources/tiles.png");
}

void TilesetWindow::resizeGL(int w, int h)
{
	GLWidget::resizeGL(256, 256);
}

void TilesetWindow::paintGL()
{
    GLWidget::paintGL();

	tileset->bindTexture();

	// draw the tileset
	Graphics::drawSprite(tileset, (Rectangle){0, 0, tileset->getWidth(), tileset->getHeight()}, (Rectangle){0, 0, tileset->getWidth(), tileset->getHeight()});

	// draw the selection
	TileSelection::drawSelection(selection.x, selection.y);
}

void TilesetWindow::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		mouseInfo.left_down = true;
	else if (e->button() == Qt::RightButton)
		mouseInfo.right_down = true;
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = true;

	// update local selection lock in grid
	selection.x = e->pos().x() - ( e->pos().x() % 16 );
	selection.y = e->pos().y() - ( e->pos().y() % 16 );
	selection.w = e->pos().x() - ( e->pos().x() % 16 ) + 16;
	selection.h = e->pos().y() - ( e->pos().y() % 16 ) + 16;

	// update global selection
	TileSelection::setSelection(selection);

	updateGL();
}

void TilesetWindow::mouseMoveEvent(QMouseEvent *e)
{
	mouseInfo.x = e->pos().x() - ( e->pos().x() % 16 );
	mouseInfo.y = e->pos().y() - ( e->pos().y() % 16 );

	if (mouseInfo.left_down)
	{
		selection.w = mouseInfo.x;
		selection.h = mouseInfo.y;
		if (selection.w >= selection.x)
			selection.w += 16;
		if (selection.h >= selection.y)
			selection.h += 16;
	}

	// update global selection
	TileSelection::setSelection(selection);

	updateGL();
}

void TilesetWindow::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
		mouseInfo.left_down = false;
	else if (e->button() == Qt::RightButton)
		mouseInfo.right_down = false;
	else if (e->button() == Qt::MiddleButton)
		mouseInfo.middle_down = false;
}
