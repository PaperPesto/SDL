#include "SDL.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized!..." << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	map = new Map();

	// ECS implementation

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/player.png");
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	cnt++;
	std::cout << cnt << std::endl;

	manager.refresh();
	manager.update();
	//std::cout << player.getComponent<TransformComponent>().
	player.getComponent<TransformComponent>().position.Add(Vector2D(0,0.1f));	// Ad ogni ciclo aggiunge un vettore (5,0)

	if (player.getComponent<TransformComponent>().position.x > 100) {
		player.getComponent<SpriteComponent>().setTex("assets/enemy.png");
	}
}

void Game::render() {
	SDL_RenderClear(renderer);

	map->DrawMap();
	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}