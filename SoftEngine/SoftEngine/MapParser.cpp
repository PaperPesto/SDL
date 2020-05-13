#include "MapParser.h"

bool MapParser::Load() {
	return Parse("level1", "assets/map.tmx");
}

void MapParser::Clean() {
}

inline GameMap* MapParser::GetMaps() {
	return nullptr;
}

bool MapParser::Parse(std::string id, std::string source) {
	return false;
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileSet) {
	Tileset tileset;
	tileset.Name = xmlTileSet->Attribute("name");
	xmlTileSet->Attribute("firstgid", &tileset.FirstID);

	xmlTileSet->Attribute("tilecount", &tileset.TileCount);
	tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

	xmlTileSet->Attribute("column", &tileset.ColCount);
	tileset.RowCount = tileset.TileCount / tileset.ColCount;
	xmlTileSet->Attribute("tilewidth", &tileset.TileSize);

	TiXmlElement* image = xmlTileSet->FirstChildElement();
	tileset.Source = image->Attribute("source");
	return tileset;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer) {
	return nullptr;
}
