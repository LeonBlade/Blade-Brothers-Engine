#include "tileselection.h"

TileSelection *TileSelection::instance = new TileSelection();

TileSelection::TileSelection()
{
	// clear tiles
	for (int i = 0; i < 256; i++)
		tiles[i] = -1;
}

TileSelection *TileSelection::getInstance()
{
	// if instance is null then initialize it
	if (TileSelection::instance == NULL)
		TileSelection::instance = new TileSelection();
	// return the instance
	return TileSelection::instance;
}

Rectangle TileSelection::getSelection()
{
	// returning the selection
	return TileSelection::instance->selection;
}

int *TileSelection::getTiles()
{
	return TileSelection::instance->tiles;
}

void TileSelection::setTile(int id, int value)
{
	TileSelection::instance->tiles[id] = value;
}

void TileSelection::setTile(int x, int y, int value)
{
	int w = abs(TileSelection::instance->selection.w - TileSelection::instance->selection.x) / 16;
	TileSelection::instance->tiles[x + (w * y)] = value;
}

void TileSelection::setSelection(Rectangle newSelection)
{
	TileSelection::instance->selection = newSelection;
	TileSelection::instance->selection.w -= TileSelection::instance->selection.x;
	TileSelection::instance->selection.h -= TileSelection::instance->selection.y;
	TileSelection::instance->selection.x = 0;
	TileSelection::instance->selection.y = 0;
}

void TileSelection::setSelection(int x, int y, int w, int h)
{
	TileSelection::instance->selection.x = 0;
	TileSelection::instance->selection.y = 0;
	TileSelection::instance->selection.w = w - x;
	TileSelection::instance->selection.h = h - y;
}

void TileSelection::drawSelection(int x, int y, bool drawTiles)
{
	// store the color
	GLfloat lastColor[4];
	glGetFloatv(GL_CURRENT_COLOR, lastColor);

	// if we are drawing the selected tiles
	if (drawTiles)
	{
		// semi-transparent
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);

		int w = (TileSelection::instance->selection.w - TileSelection::instance->selection.x) / 16;
		int h = (TileSelection::instance->selection.h - TileSelection::instance->selection.y) / 16;

		for (int i = 0; i < w * h; i++)
		{
			int cx = i % w;
			int cy = (((w - (i % w)) + i) / w) - 1;
			int tile = TileSelection::instance->tiles[cx + (w * cy)];
			int tx = tile % 16;
			int ty = (((16 - (tile % 16)) + tile) / 16) - 1;
			Graphics::drawSprite(Sprite::getLBS(), ((Rectangle){(cx * 16) + x, (cy * 16) + y, 16, 16}), ((Rectangle){tx * 16, ty * 16, 16, 16}));
		}
	}

	// disable textures in case one is binded
	glDisable(GL_TEXTURE_2D);

	// set the color to black
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	// begin drawing a line loop for the outer black line
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(TileSelection::instance->selection.x + 1 + x, TileSelection::instance->selection.y + y);
		glVertex2i(TileSelection::instance->selection.w + x, TileSelection::instance->selection.y + y);
		glVertex2i(TileSelection::instance->selection.w + x, TileSelection::instance->selection.h - 1 + y);
		glVertex2i(TileSelection::instance->selection.x + x, TileSelection::instance->selection.h - 1 + y);
	}
	glEnd();

	// set the color to white
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	// draw the middle line
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(TileSelection::instance->selection.x + 2 + x, TileSelection::instance->selection.y + 1 + y);
		glVertex2i(TileSelection::instance->selection.w - 1 + x, TileSelection::instance->selection.y + 1 + y);
		glVertex2i(TileSelection::instance->selection.w - 1 + x, TileSelection::instance->selection.h - 2 + y);
		glVertex2i(TileSelection::instance->selection.x + 1 + x, TileSelection::instance->selection.h - 2 + y);
	}
	glEnd();

	// set the color to black again
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	// draw the inner line
	glBegin(GL_LINE_LOOP);
	{
		glVertex2i(TileSelection::instance->selection.x + 3 + x, TileSelection::instance->selection.y + 2 + y);
		glVertex2i(TileSelection::instance->selection.w - 2 + x, TileSelection::instance->selection.y + 2 + y);
		glVertex2i(TileSelection::instance->selection.w - 2 + x, TileSelection::instance->selection.h - 3 + y);
		glVertex2i(TileSelection::instance->selection.x + 2 + x, TileSelection::instance->selection.h - 3 + y);
	}
	glEnd();

	// return the color to white
	glColor4fv(lastColor);

	// enable texture
	glEnable(GL_TEXTURE_2D);
}
