#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL3/SDL.h>

// 初始化图形
int init_graphics(int width, int height , SDL_Renderer **renderer , SDL_Window **window);

// 渲染一帧
void render_frame(SDL_Renderer *renderer);

// 清理图形资源
void close_graphics(SDL_Renderer *renderer, SDL_Window *window);

#endif // GRAPHICS_H
