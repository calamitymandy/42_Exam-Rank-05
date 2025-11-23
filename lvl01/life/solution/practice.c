#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av){
    if (ac != 4)
        return 1;
    
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);

    if (width <= 0 || height <= 0 || iterations < 0)
        return 1;
    
    int y = 1;
    int x = 1;
    int pen = 0;
    int grid[2][height + 2][width + 2];
    char c;

    for (int b = 0; b < 2; b++){
        for (int y = 0; y < height + 2; y++){
            for (int x = 0; x < width + 2; x++){
                grid[b][y][x] = 0;
            }
        }
    }

    while(read(0, &c, 1) > 0){
        if (c == 'w' && y > 1)
            y--;
        else if (c == 's' && y < height)
            y++;
        else if (c == 'a' && x > 1)
            x--;
        else if (c == 'd' && x < width)
            x++;
        else if (c == 'x')
            pen = !pen;
        if (pen)
            grid[0][y][x] = 1;
    }

    for (int it = 0; it < iterations; it++){
        int curr = it % 2;
        int next = (it + 1) % 2;

        for (int y = 1; y <= height; y++){
            for (int x = 1; x <= width; x++){
                int nbours = 0;

                for (int by = -1; by < 2; by++){
                    for (int bx = -1; bx < 2; bx++){
                        if (by != 0 || bx != 0)
                            nbours += grid[curr][by + y][bx + x];
                    }
                }
                if (grid[curr][y][x])
                    grid[next][y][x] = (nbours == 2 || nbours == 3);
                else
                    grid[next][y][x] = (nbours == 3);
            }
        }
    }

    int fb = iterations % 2;
    for (int y = 1; y <= height; y++){
        for (int x = 1; x <= width; x++){
            if (grid[fb][y][x])
                putchar('O');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}