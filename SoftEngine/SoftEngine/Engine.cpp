#pragma once

#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {
	m_IsRunning = true;
	return m_IsRunning;
}

bool Engine::Clean() {
	return false;
}

void Engine::Quit() {

}
void Engine::Update() {
	std::cout << "updating..." << std::endl;
}

void Engine::Render() {}
void Engine::Events() {}