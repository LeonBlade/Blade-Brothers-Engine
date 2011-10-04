#ifndef TILESELECTION_H
#define TILESELECTION_H

#include "Graphics.h"

class TileSelection
{
public:
    TileSelection();

	static TileSelection *getInstance();
	static Rectangle getSelection();
	static int *getTiles();
	static void setTile(int id, int value);
	static void setTile(int x, int y, int value);
	static void setSelection(Rectangle newSelection);
	static void setSelection(int x, int y, int w, int h);
	static void drawSelection(int x, int y, bool drawTiles = false);

private:
	static TileSelection *instance;
	Rectangle selection;
	int tiles[256];
};

#endif // TILESELECTION_H
