#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

// 游戏状态枚举
typedef enum {
    RUNNING,
    GAME_OVER, 
    QUIT
} GameState;

// 初始化游戏
void init_game();

// 处理事件
void handle_events(GameState *state);

// 更新游戏状态
void update_game(GameState *state);

// 绘制游戏元素
void draw_game(SDL_Renderer *renderer);

// 清理游戏资源
void close_game();

#endif // GAME_H
