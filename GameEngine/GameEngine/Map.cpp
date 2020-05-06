#include "Map.h"
#include "Game.h"
#include <fstream>

/*
	0 water
	1 grass
	2 dirt
*/

Map::Map() {}

Map::~Map() {}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(tile);
			Game::AddTile(atoi(&tile), x * 32, y * 32);
			mapFile.ignore();	// skip coma
		}
	}

	mapFile.close();
}
