#include "graphics.h"
#include <stdio.h>

int init_graphics(int width, int height , SDL_Renderer **renderer , SDL_Window **window) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    *window = SDL_CreateWindow("Plane Hit Game",  800, 600, SDL_WINDOW_RESIZABLE);
    if (*window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    *renderer = SDL_CreateRenderer(*window, NULL);
    if (*renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void render_frame(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
    // 此处将调用绘制函数
    SDL_RenderPresent(renderer);
}

void close_graphics(SDL_Renderer *renderer, SDL_Window *window) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
    }
    SDL_Quit();
}
