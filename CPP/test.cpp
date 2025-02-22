#include <SDL2/SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {
    // Inicializa SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crea una ventana
    SDL_Window* window = SDL_CreateWindow("Menu SDL2",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    // Crea un renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Configuración del menú:
    // Dos opciones: 0 -> "Start", 1 -> "Exit"
    const int numOptions = 2;
    int selectedOption = 0;

    // Definición de rectángulos para cada opción
    SDL_Rect optionRects[numOptions];
    optionRects[0] = { WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 60, 200, 50 }; // Opción 0: Start
    optionRects[1] = { WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 + 10, 200, 50 }; // Opción 1: Exit

    bool quit = false;
    SDL_Event event;

    // Bucle principal del menú
    while (!quit) {
        // Procesamiento de eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        selectedOption--;
                        if (selectedOption < 0) selectedOption = 0;
                        break;
                    case SDLK_DOWN:
                        selectedOption++;
                        if (selectedOption >= numOptions) selectedOption = numOptions - 1;
                        break;
                    case SDLK_RETURN:
                        // Si se presiona Enter, finaliza el menú
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
        }

        // Renderizado del menú:
        // Fondo negro
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dibuja cada opción
        for (int i = 0; i < numOptions; i++) {
            if (i == selectedOption) {
                // Opción seleccionada: fondo blanco
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &optionRects[i]);
            } else {
                // Opción no seleccionada: fondo gris con borde blanco
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
                SDL_RenderFillRect(renderer, &optionRects[i]);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &optionRects[i]);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // Aproximadamente 60 FPS
    }

    // Al salir del menú, imprime la opción seleccionada en la consola
    std::cout << "Opción seleccionada: " 
              << (selectedOption == 0 ? "Start" : "Exit") 
              << std::endl;

    // Limpieza final
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
