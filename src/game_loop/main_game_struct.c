/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** window_struct
*/
#include "../my.h"

static void get_hp_bars(game_t *game)
{
    game->hp_bars = malloc(sizeof(sfTexture *) * 7);
    game->hp_bars[0] = sfTexture_createFromFile("src/assets/0hp.png", NULL);
    game->hp_bars[1] = sfTexture_createFromFile("src/assets/1hp.png", NULL);
    game->hp_bars[2] = sfTexture_createFromFile("src/assets/2hp.png", NULL);
    game->hp_bars[3] = sfTexture_createFromFile("src/assets/3hp.png", NULL);
    game->hp_bars[4] = sfTexture_createFromFile("src/assets/4hp.png", NULL);
    game->hp_bars[5] = sfTexture_createFromFile("src/assets/5hp.png", NULL);
    game->hp_bars[6] = NULL;
    game->hp_sprite = sfSprite_create();
    sfSprite_setTexture(game->hp_sprite, game->hp_bars[5], sfTrue);
    sfSprite_setPosition(game->hp_sprite, (sfVector2f) {1320, 581});
}

static void game_init_text(game_t *game)
{
    game->font = sfFont_createFromFile("src/assets/font.ttf");
    game->score_text = sfText_create();
    sfText_setFont(game->score_text, game->font);
    sfText_setCharacterSize(game->score_text, 60);
    sfText_setFillColor(game->score_text, sfRed);
    game->highscore_text = sfText_create();
    sfText_setFont(game->highscore_text, game->font);
    sfText_setCharacterSize(game->highscore_text, 60);
    sfText_setFillColor(game->highscore_text, sfRed);
    sfText_setPosition(game->score_text, (sfVector2f) {50, 750});
    sfText_setPosition(game->highscore_text, (sfVector2f) {50, 850});
}

game_t *game_init(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->texture = sfTexture_createFromFile("src/assets/bckground.jpg",
        NULL);
    game->sprite = sfSprite_create();
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    sfSprite_setPosition(game->sprite, (sfVector2f) {0, -200});
    get_hp_bars(game);
    game->clock = sfClock_create();
    game->state = 2;
    game->fps_count = 0;
    game->score = 0;
    game->highscore = read_int_from_file();
    game->hp = 5;
    game->difficulty = 6;
    game_init_text(game);
    return game;
}

int get_time(sfClock *clock)
{
    return sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}
