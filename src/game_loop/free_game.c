/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** free_game
*/
#include "../my.h"

int get_state(int state)
{
    if (state == 84)
        return 84;
    return 2;
}

int free_game(game_t *game, sfRenderWindow *window)
{
    int state = get_state(game->state);

    sfTexture_destroy(game->texture);
    sfSprite_destroy(game->sprite);
    sfClock_destroy(game->clock);
    for (int i = 0; game->hp_bars[i] != NULL; i++)
        sfTexture_destroy(game->hp_bars[i]);
    sfSprite_destroy(game->hp_sprite);
    free(game->hp_bars);
    sfFont_destroy(game->font);
    sfText_destroy(game->score_text);
    sfText_destroy(game->highscore_text);
    free(game);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    return state;
}

void free_game_content(sfTexture ***textures, pokemon_manager_t *manager,
    masterball_t *masterball)
{
    for (int i = 0; i < manager->total_count; i++) {
        if (manager->pokemons[i] == NULL)
            continue;
        free_pokemon(&(manager->pokemons[i]));
    }
    free(manager->pokemons);
    free(manager);
    for (int i = 0; i < 4; i++) {
        for (int y = 0; textures[i][y] != NULL; y++)
            sfTexture_destroy(textures[i][y]);
        free(textures[i]);
        textures[i] = NULL;
    }
    free(textures);
    sfTexture_destroy(masterball->tex);
    sfSprite_destroy(masterball->sprite);
    free(masterball);
}

void free_pokemon(pokemon_t **pokemon)
{
    if (*pokemon == NULL)
        return;
    free((*pokemon)->textures);
    sfSprite_destroy((*pokemon)->sprite);
    free(*pokemon);
    (*pokemon) = NULL;
}
