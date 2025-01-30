/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** menu_structs
*/
#include "../my.h"

void get_menu_sprites(menu_t *menu)
{
    menu->buttons = malloc(sizeof(button_t) * 4);
    menu->buttons[0] = add_button("src/assets/Hplay.png",
        "src/assets/play.png", 1, (sfVector2f) {600, 700});
    menu->buttons[1] = add_button("src/assets/Hexit.png",
        "src/assets/exit.png", 84, (sfVector2f) {1000, 700});
    menu->buttons[2] = add_button("src/assets/down.png",
        "src/assets/down.png", -10, (sfVector2f) {1700, 20});
    menu->buttons[3] = add_button("src/assets/up.png",
        "src/assets/up.png", 10, (sfVector2f) {1800, 20});
    menu->text = sfTexture_createFromFile(
        "src/assets/menu.jpg", NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->text, sfTrue);
}

menu_t *menu_init(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    get_menu_sprites(menu);
    menu->clock = sfClock_create();
    menu->state = 0;
    menu->fps_count = 0;
    return menu;
}
