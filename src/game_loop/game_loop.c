/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** game_loop
*/
#include "../my.h"

void update_text(game_t *game)
{
    char *score_str;
    char *highscore_str;

    if (game->score > game->highscore) {
        write_int_to_file(game->score);
        game->highscore = game->score;
    }
    score_str = combine("YOUR SCORE: ", game->score);
    highscore_str = combine("HIGH SCORE: ", game->highscore);
    sfText_setString(game->score_text, score_str);
    sfText_setString(game->highscore_text, highscore_str);
    free(score_str);
    free(highscore_str);
}

int print_window(game_t *game, pokemon_manager_t *manager,
    masterball_t *master, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, game->sprite, NULL);
    sfRenderWindow_drawSprite(window, game->hp_sprite, NULL);
    for (int i = 0; i < manager->total_count; i++) {
        if (manager->pokemons[i] == NULL)
            continue;
        sfSprite_setPosition(manager->pokemons[i]->sprite,
            manager->pokemons[i]->position);
        sfRenderWindow_drawSprite(window, manager->pokemons[i]->sprite,
            NULL);
    }
    update_text(game);
    sfRenderWindow_drawText(window, game->score_text, NULL);
    sfRenderWindow_drawText(window, game->highscore_text, NULL);
    move_masterball(master, window);
    sfRenderWindow_drawSprite(window, master->sprite, NULL);
    sfRenderWindow_display(window);
    return 0;
}

void manage_mouse_click(pokemon_manager_t *manager,
    sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse_position;

    for (int i = 0; i < manager->total_count; i++) {
        if (manager->pokemons[i] == NULL)
            continue;
        mouse_position = sfMouse_getPositionRenderWindow(window);
        if (mouse_position.x > manager->pokemons[i]->position.x &&
            mouse_position.x < manager->pokemons[i]->position.x +
            manager->pokemons[i]->size.x &&
            mouse_position.y > manager->pokemons[i]->position.y &&
            mouse_position.y < manager->pokemons[i]->position.y +
            manager->pokemons[i]->size.y && game->hp != 0) {
            game->score++;
            free_pokemon(&(manager->pokemons[i]));
            }
    }
    return;
}

static int events(game_t *game, pokemon_manager_t *manager,
    sfRenderWindow *window, sfMusic *music)
{
    while (sfRenderWindow_pollEvent(window, &game->event)) {
        if (sfKeyboard_isKeyPressed(sfKeyR) ||
            game->event.type == sfEvtClosed) {
            game->state = 84;
            game->hp = 0;
        }
        if (game->event.type == sfEvtMouseButtonPressed &&
            game->event.mouseButton.button == sfMouseLeft)
            manage_mouse_click(manager, window, game);
            if (sfKeyboard_isKeyPressed(sfKeyP))
            change_volume(10, music);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            change_volume(-10, music);
    }
    return 0;
}

void move_masterball(masterball_t *masterball, sfRenderWindow *window)
{
    sfVector2i mouse_position_int = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_position = {mouse_position_int.x - 25,
        mouse_position_int.y - 25};

    sfSprite_setPosition(masterball->sprite, mouse_position);
}

int game_loop(sfRenderWindow *window, sfMusic *music)
{
    game_t *game = game_init();
    sfTexture ***textures = get_sprites();
    pokemon_manager_t *manager = init_pokemon_manager(10);
    masterball_t *masterball = masterball_init();

    srand(time(NULL));
    while (game->hp > 0) {
        if (game->fps_count % (60 + (240 / game->difficulty)) == 0 &&
            game->hp != 0)
            add_pokemon(manager, init_pokemon(textures,
                rand() % (499), game));
        events(game, manager, window, music);
        if (get_time(game->clock) < 16 * game->fps_count)
            continue;
        update_pokemons(manager, game);
        print_window(game, manager, masterball, window);
        game->fps_count++;
    }
    free_game_content(textures, manager, masterball);
    return free_game(game, window);
}
