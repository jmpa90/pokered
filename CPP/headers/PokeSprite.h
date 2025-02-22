#ifndef POKESPRITE_H
#define POKESPRITE_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

class PokeSprite {
public:
    // Constructor: posición (x, y) y escala (tamaño de cada bloque)
    PokeSprite(int x, int y, int s) : posX(x), posY(y), scale(s) {
        // Patrón muy simple de 8x8 para un "Pikachu" estilizado.
        // Cada cadena representa una fila; '1' indica dibujar un bloque, ' ' (espacio) se deja vacío.
        pattern = {
            "  11 11 ",
            " 111111 ",
            "11111111",
            "11100111",
            "11111111",
            " 111111 ",
            "  1111  ",
            "   11   "
        };
    }
    
    // Método para dibujar el sprite en el renderizador dado
    void draw(SDL_Renderer* renderer) {
        // Usamos color amarillo para representar a Pikachu
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        int rows = pattern.size();
        int cols = pattern[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pattern[i][j] == '1') {
                    SDL_Rect rect = { posX + j * scale, posY + i * scale, scale, scale };
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }
    
private:
    int posX, posY;                    // Posición base del sprite
    int scale;                         // Tamaño de cada "bloque" (píxel ampliado)
    std::vector<std::string> pattern;  // Patrón que define el sprite
};

#endif // POKESPRITE_H
