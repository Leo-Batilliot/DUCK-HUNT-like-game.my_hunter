/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** game_over_structs
*/
#include "../my.h"

button_t *add_button(char *pathon, char *pathoff, int effect,
    sfVector2f position)
{
    button_t *set = malloc(sizeof(button_t));

    set->off = sfTexture_createFromFile(pathoff, NULL);
    set->spriteoff = sfSprite_create();
    sfSprite_setTexture(set->spriteoff, set->off, sfTrue);
    set->on = sfTexture_createFromFile(pathon, NULL);
    set->spriteon = sfSprite_create();
    sfSprite_setTexture(set->spriteon, set->on, sfTrue);
    set->position = position;
    sfSprite_setPosition(set->spriteon, set->position);
    sfSprite_setPosition(set->spriteoff, set->position);
    set->size = (sfVector2i) {300, 100};
    if (effect == 10 || effect == -10)
        set->size = (sfVector2i) {100, 100};
    set->state = 0;
    set->effect = effect;
    return set;
}

void get_game_over_assets(game_over_t *game_over)
{
    game_over->buttons = malloc(sizeof(button_t) * 3);
    game_over->buttons[0] = add_button("src/assets/Hmenu.png",
        "src/assets/menu.png", 0, (sfVector2f) {380, 600});
    game_over->buttons[1] = add_button("src/assets/Hretry.png",
        "src/assets/retry.png", 1, (sfVector2f) {780, 600});
    game_over->buttons[2] = add_button("src/assets/Hexit.png",
        "src/assets/exit.png", 84, (sfVector2f) {1180, 600});
    game_over->end_text = sfTexture_createFromFile(
        "src/assets/game_over70.png", NULL);
    game_over->end = sfSprite_create();
    sfSprite_setTexture(game_over->end, game_over->end_text, sfTrue);
    game_over->text_text = sfTexture_createFromFile(
        "src/assets/game_over_text.png", NULL);
    game_over->text = sfSprite_create();
    sfSprite_setTexture(game_over->text, game_over->text_text, sfTrue);
    sfSprite_setPosition(game_over->text,
        (sfVector2f) {340, 000});
}

game_over_t *game_over_init(void)
{
    game_over_t *game_over = malloc(sizeof(game_over_t));

    get_game_over_assets(game_over);
    game_over->clock = sfClock_create();
    game_over->state = 2;
    game_over->fps_count = 0;
    return game_over;
}
