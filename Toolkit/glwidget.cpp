#include "glwidget.h"
#include "Sprite.h"
#include "Graphics.h"
#include <stdio.h>

GLWidget::GLWidget(QWidget *parent, QGLWidget *shareWidget) :
    QGLWidget(parent, shareWidget)
{
}

GLWidget::~GLWidget()
{
	// make sure to remove all our textures before quitting !
	Graphics::removeAllTextures();
}

void GLWidget::initializeGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GLWidget::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    glOrtho(0.0f, w, h, 0.0f, -1.0f, 1.0f);

	resize(w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::keyPressEvent(QKeyEvent *e)
{
	e = NULL;
}
