#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class PlayerSprite {
public:
    PlayerSprite(SDL_Renderer* renderer, const char* filepath, int x, int y, int frameWidth, int totalHeight)
        : posX(x), posY(y), frameW(frameWidth), frameH(totalHeight / 6), currentFrame(0), flip(SDL_FLIP_NONE) {

        texture = IMG_LoadTexture(renderer, filepath);
        if (!texture) {
            std::cerr << "Error al cargar la imagen: " << IMG_GetError() << std::endl;
        }
    }

    ~PlayerSprite() {
        SDL_DestroyTexture(texture);
    }

    void draw(SDL_Renderer* renderer) {
        if (texture) {
            SDL_Rect srcRect = { 0, currentFrame * frameH, frameW, frameH }; // 🔹 SOLO 1 FILA
            SDL_Rect destRect = { posX, posY, frameW * 2, frameH * 2 }; // 🔹 Escalar 2x
            SDL_RenderCopyEx(renderer, texture, &srcRect, &destRect, 0, nullptr, flip);
        }
    }

    void setFrame(int frame, bool mirror = false) {
        if (frame >= 0 && frame < 6) { // 🔹 6 filas en total
            currentFrame = frame;
            flip = mirror ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE; // 🔹 Espejar si es necesario
        }
    }

    void move(int dx, int dy) {
        posX += dx;
        posY += dy;
    }

private:
    int posX, posY;
    int frameW, frameH;
    int currentFrame; // Frame actual
    SDL_Texture* texture;
    SDL_RendererFlip flip; // 🔹 Para reflejar el sprite
};

#endif // PLAYERSPRITE_H
