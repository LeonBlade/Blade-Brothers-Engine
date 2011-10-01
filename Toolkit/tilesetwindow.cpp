#include "tilesetwindow.h"

TilesetWindow::TilesetWindow(QWidget *parent, QGLWidget *shareWidget) :
    GLWidget(parent, shareWidget)
{
	tileset = new Sprite();
	setMouseTracking(true);
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

	// draw the lovely
	Graphics::drawSprite(tileset, (Rectangle){0, 0, tileset->getWidth(), tileset->getHeight()}, (Rectangle){0, 0, tileset->getWidth(), tileset->getHeight()});
}

void TilesetWindow::mousePressEvent(QMouseEvent *e)
{

}

void TilesetWindow::mouseReleaseEvent(QMouseEvent *e)
{

}
