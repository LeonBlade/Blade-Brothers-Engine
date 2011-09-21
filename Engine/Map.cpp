/*
 * Map.cpp
 *
 *  Created on: Sep 16, 2011
 *      Author: LeonBlade
 */

#include "Map.h"
#include "Log.h"
#include "Graphics.h"

std::map<std::string, Map*> Map::maps;

Map::Map()
{
	Log::info("Constructing a map...");
	strcpy((char*)header.magic, "BBMF");
	header.name = '\0';
	header.tileset = '\0';
	header.width = 20;
	header.height = 15;
}

Map::~Map()
{
	Log::info("Deleting a map...");
	delete &header;
	delete[] tiles;
	delete[] objects;
}

void Map::onCreate(std::string name, std::string tileset, int width, int height)
{
	Log::info("Creating a new map named %s", name.c_str());

	header.name = (char*) malloc(name.length());
	strcpy(header.name, name.c_str());
	header.tileset = (char*) malloc(tileset.length());
	strcpy(header.tileset, tileset.c_str());
	header.width = width;
	header.height = height;

	sprite = Graphics::getTexture(tileset);

	tiles = (MapTile*) malloc(width*height*sizeof(MapTile));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			tiles[x+(width*y)].layer[LayerGround] = 1;
			tiles[x+(width*y)].layer[LayerMiddle] = 0;
			tiles[x+(width*y)].layer[LayerAbove] = 0;
			tiles[x+(width*y)].layer[LayerCollision] = 0;
		}
	}

	Map::maps.insert(std::pair<std::string, Map*>(name, this));
}

void Map::onLoad(std::string file)
{
	Log::info("Loading map %s...", file.c_str());
	FILE *f = fopen(file.c_str(), "rb");
	fread(&header.magic, 1, 4, f);
	char cc;
	int i = 0;
	while ((cc = (char)fgetc(f)) != 0x00)
	{
		header.name[i] = cc; i++;
	}
	i = 0;
	while ((cc = (char)fgetc(f)) != 0x00)
	{
		header.tileset[i] = cc; i++;
	}
	fread(&header.width, 1, 2, f);
	fread(&header.height, 1, 2, f);
	fread(tiles, 1, header.width*header.height*sizeof(MapTile), f);
}

void Map::onSave(std::string file)
{
	Log::info("Saving map %s...", file.c_str());
	FILE *f = fopen(file.c_str(), "wb");
	fwrite(&header.magic, 4, 1, f);
	fwrite(header.name, strlen(header.name), 1, f); 		fputc('\0', f);
	fwrite(header.tileset, strlen(header.tileset), 1, f); 	fputc('\0', f);
	fwrite(&header.width, 2, 1, f);
	fwrite(&header.height, 2, 1, f);
	fwrite(tiles, header.width*header.height*sizeof(MapTile), 1, f);
	fclose(f);
}

void Map::onUpdate()
{

}

void Map::setTile(int x, int y, MapTile tile)
{
	tiles[x+(header.width*y)] = tile;
}

MapTile Map::getTile(int x, int y)
{
	return tiles[x+(header.width*y)];
}

void Map::onDraw(MapLayer layer)
{
	sprite->bindTexture();

	for (int y = 0; y < header.height; y++)
	{
		for (int x = 0; x < header.width; x++)
		{
			int tx = 0, ty = 0;
			int tid = tiles[x+(header.width*y)].layer[layer];
			int tsw = sprite->getWidth() / 16;
			tx = (tid % tsw) * 16;
			ty = ((((tsw - (tid % tsw)) + tid) / tsw) - 1) * 16;
			Graphics::drawSprite(sprite, (Rectangle){x*16,y*16,16,16}, (Rectangle){tx,ty,16,16}, 0);
		}
	}
}