#pragma once

#include <vector>
#include "Layer.h"

class GameMap {
public:
	void Render() {
		for (unsigned int i = 0; i < m_MapLayers.size(); i++) {
			m_MapLayers[i]->Render();
		}
	}

	void Update() {
		for (unsigned int i = 0; i < m_MapLayers.size(); i++) {
			m_MapLayers[i]->Update();
		}
	}

	std::vector<Layer*> GetMapLayers() { return m_MapLayers; }

private:
	friend class MapParser;	// ? https://youtu.be/AZ2NRGdGppg?list=PL-K0viiuJ2RctP5nlJlqmHGeh66-GOZR_&t=1464
	std::vector<Layer*> m_MapLayers;
};

