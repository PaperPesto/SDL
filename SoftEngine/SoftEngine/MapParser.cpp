#include "MapParser.h"

MapParser* MapParser::s_Instance = nullptr;

bool MapParser::Load() {
	return Parse("MAP", "assets/map.tmx");
}

void MapParser::Clean() {
	std::map<std::string, GameMap*>::iterator it;
	for (it = m_MapDict.begin(); it != m_MapDict.end(); it++)
		it->second = nullptr;

	m_MapDict.clear();
}


bool MapParser::Parse(std::string id, std::string source) {
	TiXmlDocument xml;
	xml.LoadFile(source);

	if (xml.Error()) {
		std::cerr << "Failed to load: " << source << std::endl;
		return false;
	}

	TiXmlElement* root = xml.RootElement();
	int rowcount, colcount, tilesize = 0;

	root->Attribute("width", &colcount);
	root->Attribute("height", &rowcount);
	root->Attribute("tilewidth", &tilesize);

	// Parse tile sets
	TilesetList tilesets;
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("tileset")) {
			tilesets.push_back(ParseTileset(e));
		}
	}

	// parse payers
	GameMap* gamemap = new GameMap();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("layer")) {
			TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
			gamemap->m_MapLayers.push_back(tilelayer);
		}
	}

	m_MapDict[id] = gamemap;
	return true;
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileSet) {
	Tileset tileset;
	tileset.Name = xmlTileSet->Attribute("name");
	xmlTileSet->Attribute("firstgid", &tileset.FirstID);

	xmlTileSet->Attribute("tilecount", &tileset.TileCount);
	tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

	xmlTileSet->Attribute("columns", &tileset.ColCount);
	tileset.RowCount = tileset.TileCount / tileset.ColCount;
	xmlTileSet->Attribute("tilewidth", &tileset.TileSize);

	TiXmlElement* image = xmlTileSet->FirstChildElement();
	tileset.Source = image->Attribute("source");
	return tileset;
}

TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TilesetList tilesets, int tilesize, int rowcount, int colcount) {
	TiXmlElement* data{};
	for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data")) {
			data = e;
			break;
		}
	}

	// Parse layer tile map
	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	TileMap tilemap(rowcount, std::vector<int>(colcount, 0));

	for (int row = 0; row < rowcount; row++) {
		for (int col = 0; col < colcount; col++) {
			getline(iss, id, ',');
			std::stringstream converter(id);
			converter >> tilemap[row][col];

			if (!iss.good())
				break;
		}
	}

	return new TileLayer(tilesize, rowcount, colcount, tilemap, tilesets);
}
