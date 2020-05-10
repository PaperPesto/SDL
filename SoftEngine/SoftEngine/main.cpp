#include <iostream>
#include "SDL.h"
#include "Engine.h"

int main(int argc, char** argv) {

	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning()) {
		Engine::GetInstance()->Events();	// Hanle user input
		Engine::GetInstance()->Update();	// Internal calculations
		Engine::GetInstance()->Render();
	}

	Engine::GetInstance()->Clean();

	return 0;
}