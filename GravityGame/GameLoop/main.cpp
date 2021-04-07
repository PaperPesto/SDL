#include "SDL.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>

Game* game = nullptr;

int main(int argc, char* argv[]) {

	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);

	//SDL_Delay(3000);


	/*game = new Game();

	game->init("Gravity Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return EXIT_SUCCESS;*/

    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    std::cout << "1";
    SDL_Delay(2000);

    // Clear widnow
    SDL_RenderClear(renderer);
    std::cout << "2";
    SDL_Delay(2000);

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    std::cout << "3";
    SDL_Delay(2000);

    // Render rect
    SDL_RenderFillRect(renderer, &r);
    std::cout << "4";
    SDL_Delay(2000);

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
    std::cout << "5";

    // Wait for 5 sec
    SDL_Delay(5000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}