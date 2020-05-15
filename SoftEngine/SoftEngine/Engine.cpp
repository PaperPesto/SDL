#pragma once

#include "Engine.h"
#include <iostream>
#include "TextureManager.h"
#include "Transform.h"
#include "Warrior.h"
#include "Input.h"
#include "Timer.h"
#include "MapParser.h"
#include <iostream>
#include "Camera.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_WindowFlags windows_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

	m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windows_flags);
	if (m_Window == nullptr) {
		SDL_Log("Failed to create Window: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Failed to create Renderer: %s", SDL_GetError());
		return false;
	}

	if (MapParser::GetInstance()->Load()) {
		std::cout << "Failed to load map" << std::endl;
	}

	m_LevelMap = MapParser::GetInstance()->GetMap("MAP");

	TextureManager::GetInstance()->Load("player", "assets/adventurer-Sheet.png");
	TextureManager::GetInstance()->Load("bg", "assets/background.png");
	player = new Warrior(new Properties("player", 100, 200, 50, 37));

	Transform tf;
	tf.Log();

	Camera::GetInstance()->SetTarget(player->GetOrigin());

	m_IsRunning = true;
	return m_IsRunning;
}

void Engine::Update() {
	float dt = Timer::GetInstance()->GetDeltaTime();

	player->Update(dt);
	m_LevelMap->Update();
	Camera::GetInstance()->Update(dt);
}

void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);	// background color
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("bg", 0, 0, 1346, 580);
	m_LevelMap->Render();
	player->Draw();

	SDL_RenderPresent(m_Renderer);
}

void Engine::Events() {
	Input::GetInstance()->Listen();
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