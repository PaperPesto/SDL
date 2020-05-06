#pragma once

#include "Components.h"
#include "TextureManager.h"
#include <iostream>

class SpriteComponent : public Component {
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		// loading textures
		setTex(path);
	}

	void setTex(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		std::cout << "Sprite init" << std::endl;
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;	// texture scaled 2 times
	}

	void update() override {
		std::cout << "Sprite update" << std::endl;
		destRect.x = position->x();
		destRect.y = position->y();
	}

	void draw() override {
		std::cout << "x: " << destRect.x << std::endl;
		TextureManager::Draw(texture, srcRect, destRect);
	}
};