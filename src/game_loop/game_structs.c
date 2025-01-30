/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** structs
*/
#include "../my.h"

static void get_dracaufeu(sfTexture **texture)
{
    texture[0] = sfTexture_createFromFile("src/assets/dracaufeu1.png", NULL);
    texture[1] = sfTexture_createFromFile("src/assets/dracaufeu2.png", NULL);
    texture[2] = sfTexture_createFromFile("src/assets/dracaufeu3.png", NULL);
    texture[3] = sfTexture_createFromFile("src/assets/dracaufeu4.png", NULL);
    texture[4] = NULL;
}

static void get_giratina(sfTexture **texture)
{
    texture[0] = sfTexture_createFromFile("src/assets/giratina1.png", NULL);
    texture[1] = sfTexture_createFromFile("src/assets/giratina2.png", NULL);
    texture[2] = sfTexture_createFromFile("src/assets/giratina3.png", NULL);
    texture[3] = sfTexture_createFromFile("src/assets/giratina4.png", NULL);
    texture[4] = sfTexture_createFromFile("src/assets/giratina5.png", NULL);
    texture[5] = sfTexture_createFromFile("src/assets/giratina6.png", NULL);
    texture[6] = sfTexture_createFromFile("src/assets/giratina7.png", NULL);
    texture[7] = sfTexture_createFromFile("src/assets/giratina8.png", NULL);
    texture[8] = sfTexture_createFromFile("src/assets/giratina9.png", NULL);
    texture[9] = sfTexture_createFromFile("src/assets/giratina10.png", NULL);
    texture[10] = NULL;
}

static void get_darkrai(sfTexture **texture)
{
    texture[0] = sfTexture_createFromFile("src/assets/darkrai1.png", NULL);
    texture[1] = sfTexture_createFromFile("src/assets/darkrai2.png", NULL);
    texture[2] = sfTexture_createFromFile("src/assets/darkrai3.png", NULL);
    texture[3] = sfTexture_createFromFile("src/assets/darkrai4.png", NULL);
    texture[4] = sfTexture_createFromFile("src/assets/darkrai5.png", NULL);
    texture[5] = sfTexture_createFromFile("src/assets/darkrai6.png", NULL);
    texture[6] = sfTexture_createFromFile("src/assets/darkrai7.png", NULL);
    texture[7] = sfTexture_createFromFile("src/assets/darkrai8.png", NULL);
    texture[8] = sfTexture_createFromFile("src/assets/darkrai9.png", NULL);
    texture[9] = sfTexture_createFromFile("src/assets/darkrai10.png", NULL);
    texture[10] = NULL;
}

static void get_kyogre(sfTexture **texture)
{
    texture[0] = sfTexture_createFromFile("src/assets/kyogre1.png", NULL);
    texture[1] = sfTexture_createFromFile("src/assets/kyogre2.png", NULL);
    texture[2] = sfTexture_createFromFile("src/assets/kyogre3.png", NULL);
    texture[3] = sfTexture_createFromFile("src/assets/kyogre4.png", NULL);
    texture[4] = sfTexture_createFromFile("src/assets/kyogre5.png", NULL);
    texture[5] = sfTexture_createFromFile("src/assets/kyogre6.png", NULL);
    texture[6] = sfTexture_createFromFile("src/assets/kyogre7.png", NULL);
    texture[7] = sfTexture_createFromFile("src/assets/kyogre8.png", NULL);
    texture[8] = NULL;
}

sfTexture ***get_sprites(void)
{
    sfTexture ***textures = malloc(sizeof(sfTexture **) * 4);

    textures[0] = malloc(sizeof(sfTexture *) * 5);
    get_dracaufeu(textures[0]);
    textures[1] = malloc(sizeof(sfTexture *) * 11);
    get_giratina(textures[1]);
    textures[2] = malloc(sizeof(sfTexture *) * 11);
    get_darkrai(textures[2]);
    textures[3] = malloc(sizeof(sfTexture *) * 9);
    get_kyogre(textures[3]);
    return textures;
}

pokemon_manager_t *init_pokemon_manager(int capacity)
{
    pokemon_manager_t *manager = malloc(sizeof(pokemon_manager_t));

    manager->pokemons = malloc(sizeof(pokemon_t *) * capacity);
    for (int i = 0; i < capacity; i++)
        manager->pokemons[i] = NULL;
    manager->total_count = 0;
    manager->count = 0;
    manager->capacity = capacity;
    return manager;
}

void init_pokemon_textures(sfTexture ***tex, pokemon_t *pokemon, game_t *game,
    int res)
{
    int i = 0;
    int malloc_size[4] = {5, 11, 11, 9};
    int speed[4] = {5, 3, 3, 2};
    int hspeed[4] = {0, 1, 1, 2};

    pokemon->textures = malloc(sizeof(sfTexture *) * malloc_size[res]);
    if (res == 0)
        for (; i < 4; i++)
            pokemon->textures[i] = tex[res][i];
    if (res == 1 || res == 2)
        for (; i < 10; i++)
            pokemon->textures[i] = tex[res][i];
    if (res == 3)
        for (; i < 8; i++)
            pokemon->textures[i] = tex[res][i];
    pokemon->max_texture_nb = i;
    pokemon->speed = speed[res];
    pokemon->hspeed = hspeed[res];
    pokemon->textures[i] = NULL;
}

pokemon_t *init_pokemon(sfTexture ***texture, float y, game_t *game)
{
    pokemon_t *pokemon = malloc(sizeof(pokemon_t));

    init_pokemon_textures(texture, pokemon, game, rand() % 4);
    pokemon->position = (sfVector2f){0, y};
    pokemon->size = (sfVector2f){200, 200};
    pokemon->texturenb = 0;
    pokemon->streak = 0;
    pokemon->sprite = sfSprite_create();
    sfSprite_setTexture(pokemon->sprite, pokemon->textures[0], sfTrue);
    return pokemon;
}

masterball_t *masterball_init(void)
{
    masterball_t *masterball = malloc(sizeof(masterball_t));

    masterball->sprite = sfSprite_create();
    masterball->tex = sfTexture_createFromFile("src/assets/masterball.png",
        NULL);
    sfSprite_setTexture(masterball->sprite, masterball->tex, sfTrue);
    return masterball;
}
