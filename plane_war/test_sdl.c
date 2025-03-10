#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    // 初始化 SDL 视频子系统
    printf("Initializing SDL video subsystem...\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }
    printf("SDL video subsystem initialized.\n");
    // 创建窗口
    SDL_Window* window = SDL_CreateWindow("Hello, SDL3!", 800, 600, SDL_WINDOW_RESIZABLE);
    
    if (!window) {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    printf("Window created.\n");
    // 设置窗口位置为屏幕居中
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    printf("Window position set to center.\n");
    // 创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    printf("Renderer created.\n");
    if (!renderer) {
        SDL_Log("Create renderer failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // 设置渲染器的背景色为紫色
    SDL_SetRenderDrawColor(renderer, 16, 0, 16, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    printf("Renderer background color set to purple.\n");
    //事件循环
    SDL_Event event;
    bool keep_going = true;
    while (keep_going) {
        printf("Waiting for events...\n");
        SDL_WaitEvent(&event);
        // 处理事件
        printf("Event type: %d\n", event.type);
        switch (event.type) {
            case SDL_EVENT_QUIT:
                keep_going = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_ESCAPE) {
                    keep_going = false;
                }
                break;
            case SDL_EVENT_WINDOW_EXPOSED:
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                break;
        }

    }

    // 清理资源
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
