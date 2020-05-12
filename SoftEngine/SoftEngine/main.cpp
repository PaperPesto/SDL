#include <iostream>
#include "SDL.h"
#include "Engine.h"
#include "Timer.h"

int main(int argc, char** argv) {

	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning()) {
		Engine::GetInstance()->Events();	// Handle user input
		Engine::GetInstance()->Update();	// Internal calculations
		Engine::GetInstance()->Render();	// Graphic render
		Timer::GetInstance()->Tick();		// Deltatime increasing
	}

	Engine::GetInstance()->Clean();

	return 0;
}