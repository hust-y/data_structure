#include "game.h"
#include "resources.h"
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// 定义一些常量
#define PLAYER_SPEED 5
#define BULLET_SPEED 10
#define ENEMY_SPEED 3
#define WIDTH 800
#define HEIGHT 600

// 全局变量（根据需要调整）
SDL_Texture* background = NULL;
SDL_Texture* player_texture = NULL;
SDL_Texture* bullet_texture = NULL;
SDL_Texture* enemy_texture = NULL;

// 玩家结构体
typedef struct {
    SDL_FRect rect;
    int direction; // -1 左, 1 右
} Player;

Player player;

// 子弹结构体数组
#define MAX_BULLETS 100
typedef struct {
    SDL_FRect rect;
    int active;
} Bullet;

Bullet bullets[MAX_BULLETS];

// 敌人结构体数组
#define MAX_ENEMIES 10
typedef struct {
    SDL_FRect rect;
    int active;
} Enemy;

Enemy enemies[MAX_ENEMIES];

// 初始化游戏资源和状态
void init_game(SDL_Renderer *renderer) {
    // 初始化随机数种子
    srand(time(NULL));
    // if (renderer == NULL) {
    //     printf("aaaRenderer could not be created! SDL Error: %s\n", SDL_GetError());
    //     // 处理错误
    // }
    // 加载资源
    background = load_texture("pictures/background1.bmp", renderer);
    player_texture = load_texture("pictures/me1.bmp", renderer);
    bullet_texture = load_texture("pictures/bullet1.bmp", renderer);
    enemy_texture = load_texture("pictures/enemy1.bmp", renderer);
    SDL_SetTextureBlendMode(enemy_texture, SDL_BLENDMODE_BLEND); 
    if (!background || !player_texture || !bullet_texture || !enemy_texture) {
        printf("Failed to load textures!\n");
        exit(1);
    }

    // 初始化玩家
    player.rect = (SDL_FRect){WIDTH / 2 - 32, HEIGHT - 100, 64, 64};
    player.direction = 1;

    // 初始化子弹
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = 0;
    }

    // 初始化敌人
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i].active = 0;
        enemies[i].rect.w = 64; // 根据 enemy1.bmp 的实际尺寸调整
        enemies[i].rect.h = 64;
    }
}

// 处理用户输入和其他事件
void handle_events(GameState *state) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) {
            *state = QUIT;
        }
        // 处理键盘输入
        // printf("e.type = %d\n", e.type);
        if (e.type == SDL_EVENT_KEY_DOWN) {
            switch (e.key.key) {
                case SDLK_LEFT:
                    // printf("left\n");
                    player.direction = -1;
                    break;
                case SDLK_RIGHT:
                    player.direction = 1;
                    break;
                case SDLK_SPACE:
                    for (int i = 0; i < MAX_BULLETS; i++) {
                        if (!bullets[i].active) {
                            // 修正子弹初始位置（玩家中心偏上）
                            bullets[i].rect = (SDL_FRect){
                                player.rect.x + (player.rect.w / 2) - 4,  // 居中：玩家宽度/2 - 子弹宽度/2
                                player.rect.y - 16,                       // 玩家顶部上方
                                8, 16                                     // 子弹尺寸（需与纹理一致）
                            };
                            bullets[i].active = 1;
                            break;
                        }
                    }
                    break;
            }
        }
    }
}

// 更新游戏逻辑
void update_game(GameState *state){
    // 更新玩家位置
    player.rect.x += player.direction * PLAYER_SPEED;
    if (player.rect.x < 0) player.rect.x = 0;
    if (player.rect.x > WIDTH - player.rect.w) player.rect.x = WIDTH - player.rect.w;

    // 更新子弹位置
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            bullets[i].rect.y -= BULLET_SPEED;
            // 禁用超出屏幕顶部的子弹
            if (bullets[i].rect.y + bullets[i].rect.h < 0) {
                bullets[i].active = 0;
            }
        }
    }

    static Uint32 last_spawn_time = 0;
    Uint32 current_time = SDL_GetTicks();
    if (current_time - last_spawn_time > 2000) { // 2000ms = 2秒
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (!enemies[i].active) {
                // 设置敌人初始位置和尺寸
                enemies[i].rect = (SDL_FRect){
                    (float)(rand() % (WIDTH - 64)), // 随机X坐标（假设敌人宽度64）
                    -64.0f,                          // 从屏幕顶部外开始
                    64.0f, 64.0f                     // 宽度和高度（根据纹理调整）
                };
                enemies[i].active = 1;
                last_spawn_time = current_time;
                break;
            }
        }
    }

    // 更新敌人位置
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            enemies[i].rect.y += ENEMY_SPEED;
            if (enemies[i].rect.y > HEIGHT) {
                enemies[i].active = 0; // 移出屏幕后禁用
            }
        }
    }

    // 子弹与敌人的碰撞检测
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) continue;
        for (int j = 0; j < MAX_ENEMIES; j++) {
            if (!enemies[j].active) continue;
            if (SDL_HasRectIntersectionFloat(&bullets[i].rect, &enemies[j].rect)) {
                bullets[i].active = 0;
                enemies[j].active = 0;
                break;
            }
        }
    }

    // 玩家与敌人的碰撞检测
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active && SDL_HasRectIntersectionFloat(&player.rect, &enemies[i].rect)) {
            *state = GAME_OVER; // 碰撞后更新状态为 GAME_OVER
            break;
        }
    }
}

// 绘制游戏元素到渲染器
void draw_game(SDL_Renderer *renderer) {
    // 绘制背景
    SDL_RenderTexture(renderer, background, NULL, NULL);

    // 绘制玩家
    SDL_RenderTexture(renderer, player_texture, NULL, &player.rect);

    // 绘制子弹
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            SDL_RenderTexture(renderer, bullet_texture, NULL, &bullets[i].rect);
        }
    }

    // 绘制敌人（示例）
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].active) {
            SDL_RenderTexture(renderer, enemy_texture, NULL, &enemies[i].rect);
        }
    }
}

// 清理资源
void close_game() {
    free_texture(&background);
    free_texture(&player_texture);
    free_texture(&bullet_texture);
    free_texture(&enemy_texture);
}