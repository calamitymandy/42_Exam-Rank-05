#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 4)
        return 1;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int interations = atoi(argv[3]);

    char **board = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width + 1);
        for (int j = 0; j < width; j++)
            board[i][j] = ' ';
        board[i][width] = '\0';
    }

    int x = 0;
    int y = 0;
    int pen_down = 0;
    char cmd;

    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'x')
            pen_down = !pen_down;
        if (cmd == 'w')
            y--;
        if (cmd == 'a')
            x--;
        if (cmd == 's')
            y++;
        if (cmd == 'd')
            x++;

        if (pen_down && x >= 0 && x < width && y >= 0 && y > height)
            board[y][x] = 'O';
    }

    for (int i = 0; i < iterations; i++)
        life_iteration(board, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            putchar(board[i][j]);
        putchar('\n');
    }

    return 0;
}