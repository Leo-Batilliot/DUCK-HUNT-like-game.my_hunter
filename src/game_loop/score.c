/*
** EPITECH PROJECT, 2024
** B-MUL-100-LIL-1-1-myhunter-leo.batilliot
** File description:
** score
*/

#include "../my.h"

int get_len(char *str, int nb)
{
    int i = 0;

    if (str != NULL) {
        for (; str[i] != '\0'; i++)
            i++;
        return i;
    }
    if (nb == 0)
        return 1;
    for (; nb != 0; i++)
        nb /= 10;
    return i;
}

char *combine(char *text, int score)
{
    int i = get_len(text, score);
    int j = get_len(NULL, score);
    int x = 0;
    char *res;

    res = malloc(i + j + 1);
    for (; x < i; x++)
        res[x] = text[x];
    for (int k = j - 1; k >= 0; k--) {
        res[x + k] = (score % 10) + '0';
        score /= 10;
    }
    res[x + j] = '\0';
    return res;
}

static int str_to_int(char *str)
{
    int res = 0;

    if (str == NULL)
        return res;
    for (int i = 0; str[i] != '\0'; i++) {
        res = 10 * res + (str[i] - '0');
    }
    return res;
}

int read_int_from_file(void)
{
    int fd = open("src/highscore.txt", O_RDONLY);
    char buffer[32];
    long size;

    if (fd == -1)
        return 84;
    size = read(fd, buffer, sizeof(buffer) - 1);
    if (size == -1) {
        close(fd);
        return 84;
    }
    buffer[size] = '\0';
    close(fd);
    return str_to_int(buffer);
}

int int_to_str(int number, char *buffer)
{
    int i = 0;
    char temp;

    for (; number > 0; i++) {
        buffer[i] = '0' + (number % 10);
        number /= 10;
    }
    buffer[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
    return i;
}

void write_int_to_file(int number)
{
    int fd = open("src/highscore.txt", O_WRONLY | O_TRUNC);
    char buffer[32];
    int length;

    if (fd == -1)
        return;
    length = int_to_str(number, buffer);
    write(fd, buffer, length);
    close(fd);
}
