#include "resources.h"
#include <stdio.h>

SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer) {
    SDL_Texture* new_texture = NULL;
    SDL_Surface* loaded_surface = SDL_LoadBMP(path);
    if (loaded_surface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    } else {
        if (renderer == NULL) {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            // 处理错误
        }
        new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        //printf("Texture loaded successfully!\n");
        if (new_texture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }
        SDL_DestroySurface(loaded_surface);
    }
    return new_texture;
}

void free_texture(SDL_Texture** texture) {
    if (*texture) {
        SDL_DestroyTexture(*texture);
        *texture = NULL;
    }
}
