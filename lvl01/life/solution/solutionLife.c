#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Count live neighbors around a cell
int count_neighbors(char **board, int width, int height, int x, int y) {
    int count = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i == y && j == x) 
                continue;
            if (i >= 0 && i < height && j >= 0 && j < width && board[i][j] == 'o')
                count++;
        }
    }
    return count;
}

// Run one iteration of Game of Life
void game_of_life_iteration(char **board, int width, int height) {
    char **new_board = malloc(height * sizeof(char*));
    
    // Create new board
    for (int i = 0; i < height; i++) {
        new_board[i] = malloc(width + 1);
        for (int j = 0; j < width; j++) {
            int neighbors = count_neighbors(board, width, height, j, i);
            
            if (board[i][j] == 'o') {
                // Live cell: survives with 2 or 3 neighbors
                new_board[i][j] = (neighbors == 2 || neighbors == 3) ? 'o' : ' ';
            } else {
                // Dead cell: becomes alive with exactly 3 neighbors
                new_board[i][j] = (neighbors == 3) ? 'o' : ' ';
            }
        }
        new_board[i][width] = '\0';
    }
    
    // Copy new board to old board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Print the board
void print_board(char **board, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc != 4)
        return 1;
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    
    // Create empty board
    char **board = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width + 1);
        for (int j = 0; j < width; j++) {
            board[i][j] = ' ';
        }
        board[i][width] = '\0';
    }
    
    // Drawing pen starts at top-left
    int x = 0, y = 0, pen_down = 0;
    
    // Read drawing commands and draw pattern
    char cmd;
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'x') 
            pen_down = !pen_down;
        if (cmd == 'w' && y > 0) 
            y--;
        if (cmd == 's' && y < height - 1) 
            y++;
        if (cmd == 'a' && x > 0) 
            x--;
        if (cmd == 'd' && x < width - 1) 
            x++;
        
        // Draw if pen is down and in bounds
        if (pen_down && x >= 0 && x < width && y >= 0 && y < height) {
            board[y][x] = 'o';
        }
    }
    
    // Run Game of Life iterations
    for (int i = 0; i < iterations; i++) {
        game_of_life_iteration(board, width, height);
    }
    
    // Print final result
    print_board(board, width, height);
    
    return 0;
}