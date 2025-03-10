#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL3/SDL.h>

// 加载图像
SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer);

// 释放纹理
void free_texture(SDL_Texture** texture);

#endif // RESOURCES_H
