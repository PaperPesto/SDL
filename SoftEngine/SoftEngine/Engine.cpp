#pragma once

#include "Engine.h"
#include <iostream>
#include "TextureManager.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}

	m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr) {
		SDL_Log("Failed to create Window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create Renderer: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("tree", "assets/tree.png");

	m_IsRunning = true;
	return m_IsRunning;
}

void Engine::Update() {
	//std::cout << "updating..." << std::endl;
}

void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);	// background color
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("tree", 100, 100, 347, 465);

	SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}
}

bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();

	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
	IMG_Quit();

	return false;
}

void Engine::Quit() {
	m_IsRunning = false;
}