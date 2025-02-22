#ifndef LETTERP_H
#define LETTERP_H

#include <SDL2/SDL.h>

class LetterP {
public:
    // Constructor: posición base (x,y) y tamaño de cada bloque
    LetterP(int x, int y, int s) : base_x(x), base_y(y), scale(s) {}

    // Método para dibujar la letra "P"
    void draw(SDL_Renderer* renderer) {
        // Línea vertical izquierda (100 píxeles de alto)
        for (int i = 0; i < 100; i += scale) {
            SDL_Rect rect = { base_x, base_y + i, scale, scale };
            SDL_RenderFillRect(renderer, &rect);
        }
        // Línea horizontal superior (50 píxeles de ancho)
        for (int i = 0; i < 50; i += scale) {
            SDL_Rect rect = { base_x + i, base_y, scale, scale };
            SDL_RenderFillRect(renderer, &rect);
        }
        // Línea horizontal intermedia (40 píxeles de ancho, a 50 píxeles de la parte superior)
        for (int i = 0; i < 40; i += scale) {
            SDL_Rect rect = { base_x + i, base_y + 50, scale, scale };
            SDL_RenderFillRect(renderer, &rect);
        }
        // Línea vertical derecha de la parte superior (50 píxeles de alto)
        for (int i = 0; i < 50; i += scale) {
            SDL_Rect rect = { base_x + 50, base_y + i, scale, scale };
            SDL_RenderFillRect(renderer, &rect);
        }
    }

private:
    int base_x, base_y; // Posición base de la letra
    int scale;          // Tamaño de cada bloque
};

#endif // LETTERP_H
