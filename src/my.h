/*
** EPITECH PROJECT, 2024
** myh
** File description:
** task 02
*/
#ifndef TEST_H
    #define TEST_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include <math.h>
    #include <fcntl.h>

typedef struct {
    sfFont *font;
    sfText *score_text;
    sfText *highscore_text;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfTexture **hp_bars;
    sfSprite *hp_sprite;
    int difficulty;
    int score;
    int highscore;
    int hp;
    int state;
    int fps_count;
} game_t;

typedef struct {
    sfVector2f position;
    sfVector2f size;
    sfColor color;
    sfTexture **textures;
    sfSprite *sprite;
    int texturenb;
    int max_texture_nb;
    int speed;
    int hspeed;
    int hspeedmodif;
    int streak;
} pokemon_t;

typedef struct {
    pokemon_t **pokemons;
    int total_count;
    int count;
    int capacity;
} pokemon_manager_t;

typedef struct {
    sfSprite *spriteoff;
    sfTexture *off;
    sfSprite *spriteon;
    sfTexture *on;
    sfVector2f position;
    sfVector2i size;
    int state;
    int effect;
} button_t;

typedef struct {
    sfClock *clock;
    sfEvent event;
    sfSprite *end;
    sfTexture *end_text;
    sfTexture *text_text;
    sfSprite *text;
    button_t **buttons;
    int state;
    int fps_count;
} game_over_t;

typedef struct {
    sfClock *clock;
    sfEvent event;
    sfSprite *sprite;
    sfTexture *text;
    button_t **buttons;
    int state;
    int fps_count;
} menu_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *tex;
} masterball_t;

int game_loop(sfRenderWindow *, sfMusic *);
int menu_loop(sfRenderWindow *window, sfMusic *);
menu_t *menu_init(void);
int free_menu(menu_t *menu);
int main(int ac, char **av);
game_t *game_init(void);
masterball_t *masterball_init(void);
int free_game(game_t *game, sfRenderWindow *);
pokemon_t *init_pokemon(sfTexture ***, float y, game_t *);
void free_pokemon(pokemon_t **pokemon);
pokemon_manager_t *init_pokemon_manager(int);
void free_game_content(sfTexture ***, pokemon_manager_t *, masterball_t *);
void add_pokemon(pokemon_manager_t *manager, pokemon_t *pokemon);
void update_pokemons(pokemon_manager_t *manager, game_t *game);
sfTexture ***get_sprites(void);
int main_loop(sfRenderWindow *, sfMusic *, int state);
int get_time(sfClock *);
void move_masterball(masterball_t *masterball, sfRenderWindow *);
int game_over_loop(sfRenderWindow *window, sfMusic *);
int free_game_over(game_over_t *game_over);
game_over_t *game_over_init(void);
button_t *add_button(char *pathon, char *pathoff, int effect, sfVector2f);
char *combine(char *text, int score);
int read_int_from_file(void);
void write_int_to_file(int number);
void change_volume(int effect, sfMusic *music);

#endif /* TEST_H */
