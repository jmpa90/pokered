#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "headers/PlayerSprite.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("Player Animation",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Cargar el sprite (16 px de ancho, 96 px de alto)
    PlayerSprite player(renderer, "blue.png", 300, 200, 16, 96);

    bool quit = false;
    SDL_Event event;
    int frame = 0; // Empieza de frente

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT:
                        frame = 5; // 🔹 Izquierda caminando pero espejado (derecha)
                        player.setFrame(frame, true); // 🔹 Activamos espejo
                        player.move(5, 0);
                        break;
                    case SDLK_LEFT:
                        frame = 5; // 🔹 Izquierda caminando
                        player.setFrame(frame, false);
                        player.move(-5, 0);
                        break;
                    case SDLK_DOWN:
                        frame = 3; // 🔹 Abajo caminando
                        player.setFrame(frame);
                        player.move(0, 5);
                        break;
                    case SDLK_UP:
                        frame = 4; // 🔹 Arriba caminando
                        player.setFrame(frame);
                        player.move(0, -5);
                        break;
                    case SDLK_SPACE:
                        frame = 0; // 🔹 Idle de frente
                        player.setFrame(frame);
                        break;
                    case SDLK_x:
                        frame = 1; // 🔹 Idle de espaldas
                        player.setFrame(frame);
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dibujar el sprite con el frame actual
        player.draw(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(100); // Pequeño retraso para controlar la animación
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
