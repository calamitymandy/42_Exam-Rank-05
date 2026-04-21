//width (nb of columns), height (nb of rows), iterations
//w (up) a (left) s (down) d (right) x (start / stop)
//alive '0' ; dead ' '

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char** av){
    if (ac != 4)
        return 1;

    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iterations = atoi(av[3]);

    if (width < 0 || height < 0 || iterations < 0)
        return 1;

    //pen state and grid declaration    
    int y = 1; //pen pos y (height / row)
    int x = 1; //pen pos x (width / column)
    int pen = 0; //pen state (0 for off, 1 for on)
    int grid[2][height + 2][width + 2]; //3D array - [dimension][height][width] // +2 gives 1 cell border on each side
    char c; //holds each input from stdin

    //0 for the whole grid
    for (int d = 0; d < 2; d++){ //dimension
        for (int y = 0; y < height + 2; y++){ //row
            for (int x = 0; x < width + 2;  x++) //column
                grid[d][y][x] = 0;
        }
    }

    //reading commands from stdin into c
    while(read(0, &c, 1) > 0){
        if (c == 'w' && y > 1) //if up, y (row nb) decreases
            y--;
        else if (c == 's' && y < height) //if up, y (row nb) decreases
            y++;
        else if (c == 'a' && x > 1) //if left, y (row nb) decreases
            x--;
        else if (c == 'd' && x < width) //if up, y (row nb) decreases
            x++;
        else if (c == 'x') //if pen and pen off, pen on. if pen and pen on, pen off
            pen = !pen;
        if (pen) //if pen on, mark that position of grid 0 as alive (1)
            grid[0][y][x] = 1; //grid 0 is the initial buffer that marks alive positions (1)in the map
    }

    //game of life iterations loop
    for (int it = 0; it < iterations; it++){ //loop the nb of iterations
        int cur = it % 2; // index of the board buffer for curr iteration
        int next = (it + 1) % 2; //index of the board buffer for next iteration
        
        for (int y = 1; y <= height; y++){
            for (int x = 1; x <= width; x++){
                //count neighbours 
                int nbours = 0; //nb of alive neighbours (out of 8)
                for (int dy = -1; dy <= 1; dy++){ //dy - 1 is center -1 row (up)
                    for (int dx = -1; dx <= 1; dx++){ //dx - 1 is center -1 column (left)
                        if (dx != 0 || dy != 0) //0 is the center cell which is not counted
                            nbours += grid[cur][y + dy][x + dx]; //which can be 0 or 1
                    }
                }
                if (grid[cur][y][x] == 1) //cell is alive
                    grid[next][y][x] = (nbours == 2 || nbours == 3); //survives into next gen if 2 or 3 neighbours
                else
                    grid[next][y][x] = (nbours == 3); //becomes alive if it has 3 neighbours
            }
        } //before the next iteration, grid[next] will hold the full updated board
    } 

    //print the final board
    int final = iterations % 2; //grid[0] or grid[1] is the final board, depending on the nb of iterations
    for (int y = 1; y <= height; y++){ //i is height (rows), j is width (columns)
        for (int x = 1; x <= width; x++){
            if (grid[final][y][x]) //if current cell 1, print '0'
                putchar('O');
            else //if current cell 0, print ' '
                putchar(' ');
        }
        putchar('\n'); //new line at the end of each row
    }
}
