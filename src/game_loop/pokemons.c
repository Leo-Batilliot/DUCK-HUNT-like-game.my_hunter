/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** pokemons
*/

#include "../my.h"

void switch_pokemon_texture(game_t *game, pokemon_t *pokemon)
{
    if (game->fps_count % 8 == 0) {
        pokemon->texturenb = (pokemon->texturenb + 1) %
            pokemon->max_texture_nb;
        sfSprite_setTexture(pokemon->sprite,
            pokemon->textures[pokemon->texturenb], sfTrue);
    }
}

int move_pokemon(pokemon_t *pokemon, game_t *game)
{
    switch_pokemon_texture(game, pokemon);
    pokemon->position.x += (0.25) * pokemon->speed * game->difficulty;
    if (pokemon->position.x + pokemon->size.x >= 1920)
        return 84;
    if (pokemon->streak <= 0) {
        pokemon->streak = 15;
        pokemon->hspeedmodif = ((rand() % (2 * pokemon->hspeed + 1)) -
            pokemon->hspeed);
        pokemon->hspeedmodif *= game->difficulty;
    }
    pokemon->streak--;
    if (pokemon->position.y + pokemon->hspeedmodif < 500 &&
        pokemon->position.y + pokemon->hspeedmodif > 0 && pokemon->hspeed != 0)
        pokemon->position.y += pokemon->hspeedmodif;
    return 0;
}

void update_pokemons(pokemon_manager_t *manager, game_t *game)
{
    int start = 0;

    if (game->fps_count > 500 * game->difficulty)
        game->difficulty++;
    for (int i = 0; i < manager->total_count; i++) {
        start = game->hp;
        if (manager->pokemons[i] == NULL)
            continue;
        if (move_pokemon(manager->pokemons[i], game) == 84) {
            game->hp--;
            free_pokemon(&(manager->pokemons[i]));
        }
        if (start != game->hp && game->hp >= 0)
            sfSprite_setTexture(game->hp_sprite, game->hp_bars[game->hp],
                sfTrue);
    }
}

void add_pokemon(pokemon_manager_t *manager, pokemon_t *pokemon)
{
    manager->pokemons[manager->count % manager->capacity] = pokemon;
    manager->count++;
    if (manager->total_count < 10)
        manager->total_count++;
}
