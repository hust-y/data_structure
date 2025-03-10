#include "graphics.h"
#include "game.h"
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

SDL_Renderer* renderer = NULL;
SDL_Window* window = NULL;

int main(int argc, char* args[]) {
    GameState state = RUNNING;

    if (init_graphics(WIDTH, HEIGHT , &renderer, &window)) {
        return -1;
    }
    if (renderer == NULL) {
        printf("bbbRenderer could not be created! SDL Error: %s\n", SDL_GetError());
        // 处理错误
    }
    init_game(renderer);
    
    while (state == RUNNING) {
        handle_events(&state);
        update_game(&state);
        // 先绘制游戏元素，再渲染提交
        SDL_RenderClear(renderer);
        draw_game(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    if (state == GAME_OVER) {
        printf("Game Over!\n");
        // 可以在此处添加游戏结束画面或延迟
    }
    close_game();
    close_graphics(renderer, window);

    system("pause");

    return 0;
}