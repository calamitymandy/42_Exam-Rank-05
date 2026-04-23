#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int count_around(char **board, int width, int height, int x, int y) {
    int count = 0;
    for (int i = y-1; i <= y+1; i++) {
        for (int j = x-1; j <= x+1; j++) {
            if (i == y && j == x)
                continue;
            if (board[i][j] == 'O')
                count++;
        }
    }
    return count;
}

void life_iteration(char **board, int width, int height) {
    char **newboard = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        newboard[i] = malloc(width +1);
        for (int j = 0; j < height; j++) {
            int around = count_around(board, width, height, j, i);
            if (board[i][j] == 'O')
                newboard[i][j] = (around == 2 || around == 3) ? 'O' : ' ';
            else
                newboard[i][j] = (around == 3) ? 'O' : ' ';
        }
        newboard[i][width] = '\0';
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            board[i][j] = newboard[i][j];
        free(newboard[i]);
    }
    free(newboard);
}

int main(int argc, char **argv) {
    if (argc != 4)
        return 1;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);

    if (width < 0 || height < 0 || iterations < 0)
        return 1;

    char **board = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width +1);
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
        if (cmd == 'w' && y > 0)
            y--;
        if (cmd == 'a' && x > 0)
            x--;
        if (cmd == 's' && y < height)
            y++;
        if (cmd == 'd' && x < width)
            x++;
        if (pen_down)
            board[y][x] = 'O';
    }

    for (int i = 0; i < iterations; i++)
        life_iteration(board, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            putchar(board[i][j]);
        putchar('\n');
        free(board[i]);
    }
    free(board);
    return 0;
}