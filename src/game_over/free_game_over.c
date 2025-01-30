/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** free_game_over
*/
#include "../my.h"

int free_game_over(game_over_t *game_over)
{
    int state = game_over->state;

    sfClock_destroy(game_over->clock);
    sfTexture_destroy(game_over->end_text);
    sfSprite_destroy(game_over->end);
    sfTexture_destroy(game_over->text_text);
    sfSprite_destroy(game_over->text);
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(game_over->buttons[i]->off);
        sfTexture_destroy(game_over->buttons[i]->on);
        sfSprite_destroy(game_over->buttons[i]->spriteoff);
        sfSprite_destroy(game_over->buttons[i]->spriteon);
        free(game_over->buttons[i]);
    }
    free(game_over->buttons);
    free(game_over);
    return state;
}
