/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** free_menu
*/
#include "../my.h"

int free_menu(menu_t *menu)
{
    int state = menu->state;

    sfClock_destroy(menu->clock);
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->text);
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(menu->buttons[i]->off);
        sfTexture_destroy(menu->buttons[i]->on);
        sfSprite_destroy(menu->buttons[i]->spriteoff);
        sfSprite_destroy(menu->buttons[i]->spriteon);
        free(menu->buttons[i]);
    }
    free(menu->buttons);
    free(menu);
    return state;
}
