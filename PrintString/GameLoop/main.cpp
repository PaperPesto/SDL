#include "SDL.h"
#include <SDL_ttf.h>


int main(int argc, char* argv[]) {

    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("SDL_ttf in SDL2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
        640, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    TTF_Font* font = TTF_OpenFont("arial/arial.ttf", 10);
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, "DIAHANE", color);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

    return 0;
}