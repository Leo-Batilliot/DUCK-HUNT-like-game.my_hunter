/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** game_over_loop
*/
#include "../my.h"

int print_game_over_window(game_over_t *game_over, sfRenderWindow *window)
{
    for (int i = 0; i < 3; i++) {
        if (game_over->buttons[i]->state == 0)
            sfRenderWindow_drawSprite(window, game_over->buttons[i]->spriteoff,
                NULL);
        else
            sfRenderWindow_drawSprite(window, game_over->buttons[i]->spriteon,
                NULL);
    }
    sfRenderWindow_display(window);
    return 0;
}

void manage_over_mouse_click(game_over_t *game_over, sfRenderWindow *window,
    int option)
{
    sfVector2i m_p = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < 3; i++) {
        game_over->buttons[i]->state = 0;
        if (m_p.x > game_over->buttons[i]->position.x && m_p.x <
            game_over->buttons[i]->position.x + 300 && m_p.y >
            game_over->buttons[i]->position.y && m_p.y <
            game_over->buttons[i]->position.y + 100)
            game_over->buttons[i]->state = 1;
    }
    if (option == 0)
        return;
    for (int i = 0; i < 3; i++) {
        if (m_p.x > game_over->buttons[i]->position.x && m_p.x <
            game_over->buttons[i]->position.x + 300 && m_p.y >
            game_over->buttons[i]->position.y && m_p.y <
            game_over->buttons[i]->position.y + 100)
            game_over->state = game_over->buttons[i]->effect;
    }
}

int game_over_events(game_over_t *game_over, sfRenderWindow *window,
    sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &game_over->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyR) ||
            game_over->event.type == sfEvtClosed) {
            game_over->state = 84;
        }
        if (game_over->event.type == sfEvtMouseButtonPressed &&
            game_over->event.mouseButton.button == sfMouseLeft)
            manage_over_mouse_click(game_over, window, 1);
        if (sfKeyboard_isKeyPressed(sfKeyP))
            change_volume(10, music);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            change_volume(-10, music);
    }
    return 0;
}

int game_over_loop(sfRenderWindow *window, sfMusic *music)
{
    game_over_t *game_over = game_over_init();

    sfRenderWindow_drawSprite(window, game_over->end, NULL);
    sfRenderWindow_drawSprite(window, game_over->text, NULL);
    srand(time(NULL));
    while (game_over->state == 2) {
        game_over_events(game_over, window, music);
        if (get_time(game_over->clock) < 16)
            continue;
        manage_over_mouse_click(game_over, window, 0);
        print_game_over_window(game_over, window);
        game_over->fps_count++;
        sfClock_restart(game_over->clock);
    }
    return free_game_over(game_over);
}
