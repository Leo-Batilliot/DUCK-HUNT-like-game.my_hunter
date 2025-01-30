/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** main file
*/
#include "my.h"

int is_invalid_arg(char *str)
{
    char *res = "-h";
    int i = 0;

    for (i; str[i] != '\0'; i++);
    for (int z = 0; res[z] != '\0' && str[z] != '\0'; z++)
        if (res[z] != str[z])
            return 84;
    if (i != 2)
        return 84;
    write(1, "MY HUNTER GAME : \n", 18);
    write(1, "CLICK ON THE POKEMONS BEFORE THEY ", 34);
    write(1, "HIT THE RIGHT EDGE OF THE SCREEN !\n", 35);
    write(1, "You can close the game at any moment using the escape key", 57);
    write(1, "\nYou can aslo change the music volume to your liking ", 53);
    write(1, "using the p(plus) and m(minus) keys\n", 37);
    return 0;
}

int main_loop(sfRenderWindow *window, sfMusic *music, int state)
{
    if (sfRenderWindow_isOpen(window)) {
        if (state == 0)
            main_loop(window, music, menu_loop(window, music));
        if (state == 1) {
            sfRenderWindow_setMouseCursorVisible(window, sfFalse);
            main_loop(window, music, game_loop(window, music));
        }
        if (state == 2)
            main_loop(window, music, game_over_loop(window, music));
        if (state == 84)
            return 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfMusic* music = sfMusic_createFromFile("src/assets/Summer_Undella.ogg");

    sfMusic_setVolume(music, 50.0);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    if (ac > 2 || (ac == 2 && is_invalid_arg(av[1]) == 84)) {
        write(2, "Invalid argument(s), use -h for help\n", 37);
        return 84;
    }
    if (ac == 1) {
        window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
        "My Hunter game", sfDefaultStyle, NULL);
        sfRenderWindow_setFramerateLimit(window, 60);
        main_loop(window, music, 0);
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        sfMusic_destroy(music);
    }
    return 0;
}
