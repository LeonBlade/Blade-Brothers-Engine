/*
 * Map.h
 *
 *  Created on: Sep 16, 2011
 *      Author: LeonBlade
 */

#ifndef MAP_H_
#define MAP_H_

#include <stdlib.h>
#include <string>
#include <map>

#include "Sprite.h"

struct MapHeader
{
	unsigned char magic[4];
	char *name;
	char *tileset;
	uint16_t width;
	uint16_t height;
};

struct MapTile
{
	uint8_t layer[3];
	bool collide;
};

struct MapObject
{
	uint8_t id;
	uint16_t x;
	uint16_t y;
	char *script;
};

enum MapLayer
{
	LayerGround = 0,
	LayerMiddle = 1,
	LayerAbove = 2,
	LayerCollision = 3
};

class Map
{
public:
	Map();
	virtual ~Map();

	void onCreate(std::string name, std::string tileset, int width, int height);
	void onLoad(std::string file);
	void onSave(std::string file);
	void onUpdate();
	void onDraw(MapLayer layer);

	void setTile(int x, int y, MapTile tile);
	void setTile(int x, int y, int tid, MapLayer layer);
	MapTile getTile(int x, int y);
	int getTile(int x, int y, MapLayer layer);

	int getWidth();
	int getHeight();

private:
	MapHeader header;
	MapTile *tiles;
	MapObject *objects;
	Sprite *sprite;
	static std::map<std::string, Map*> maps;
};

#endif /* MAP_H_ */
