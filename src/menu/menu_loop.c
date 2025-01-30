/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** menu_loop
*/
#include "../my.h"

int print_menu_window(menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    for (int i = 0; i < 4; i++) {
        if (menu->buttons[i]->state == 0)
            sfRenderWindow_drawSprite(window, menu->buttons[i]->spriteoff,
                NULL);
        else
            sfRenderWindow_drawSprite(window, menu->buttons[i]->spriteon,
                NULL);
    }
    sfRenderWindow_display(window);
    return 0;
}

void manage_menu_mouse_click(menu_t *menu, sfRenderWindow *window,
    int option)
{
    sfVector2i m_p = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < 2; i++) {
        menu->buttons[i]->state = 0;
        if (m_p.x > menu->buttons[i]->position.x && m_p.x <
            menu->buttons[i]->position.x + 300 && m_p.y >
            menu->buttons[i]->position.y && m_p.y <
            menu->buttons[i]->position.y + 100)
            menu->buttons[i]->state = 1;
    }
    if (option == 0)
        return;
    for (int i = 0; i < 2; i++) {
        if (m_p.x > menu->buttons[i]->position.x && m_p.x <
            menu->buttons[i]->position.x + 300 && m_p.y >
            menu->buttons[i]->position.y && m_p.y <
            menu->buttons[i]->position.y + 100)
            menu->state = menu->buttons[i]->effect;
    }
}

void change_volume(int effect, sfMusic *music)
{
    float currentVolume = sfMusic_getVolume(music);

    if (effect == 10) {
        if (currentVolume <= 90.0)
            sfMusic_setVolume(music, currentVolume + 10.0);
        return;
    }
    if (effect == -10) {
        if (currentVolume >= 10.0)
            sfMusic_setVolume(music, currentVolume - 10.0);
        return;
    }
}

static void volume_buttons(menu_t *menu, sfMusic *music,
    sfRenderWindow *window)
{
    sfVector2i m_p = sfMouse_getPositionRenderWindow(window);

    for (int i = 2; i < 4; i++) {
        menu->buttons[i]->state = 0;
        if (m_p.x > menu->buttons[i]->position.x && m_p.x <
            menu->buttons[i]->position.x + menu->buttons[i]->size.x && m_p.y >
            menu->buttons[i]->position.y && m_p.y <
            menu->buttons[i]->position.y + menu->buttons[i]->size.y)
            change_volume(menu->buttons[i]->effect, music);
    }
}

int menu_events(menu_t *menu, sfRenderWindow *window, sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &menu->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
            menu->event.type == sfEvtClosed) {
            menu->state = 84;
        }
        if (menu->event.type == sfEvtMouseButtonPressed &&
            menu->event.mouseButton.button == sfMouseLeft) {
            manage_menu_mouse_click(menu, window, 1);
            volume_buttons(menu, music, window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyP))
            change_volume(10, music);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            change_volume(-10, music);
    }
    return 0;
}

int menu_loop(sfRenderWindow *window, sfMusic *music)
{
    menu_t *menu = menu_init();

    srand(time(NULL));
    while (menu->state == 0) {
        menu_events(menu, window, music);
        if (get_time(menu->clock) < 16 * menu->fps_count)
            continue;
        manage_menu_mouse_click(menu, window, 0);
        print_menu_window(menu, window);
        menu->fps_count++;
    }
    return free_menu(menu);
}
