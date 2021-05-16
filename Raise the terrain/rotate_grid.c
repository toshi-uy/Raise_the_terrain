#include "raise.h"
#include <math.h>

/**
 * rotate_grid - function to handle the grid rotation on key event
 * @terrain: pointer to global structure
 * @angle: angle to change the coordinates
 *
 */

void rotate_grid(raise_t *terrain, int angle)
{
    int i, j;
    float x, y, z, Cx, Cy;
    float a, Rx, Ry;
    
    a = angle * M_PI / 180;
    Cx = WIDTH / 4;
    Cy = HEIGHT / 3;
    
    for (i = 0; i < terrain->rows; i++)
        for (j = 0; j < terrain->columns; j++)
        {
            x = terrain->array[i][j].x;
            y = terrain->array[i][j].y;
            Rx = (x - Cx) * cos(a) - (y - Cy) * sin(a) + Cx;
            Ry = (x - Cx) * sin(a) + (y - Cy) * cos(a) + Cy;
            terrain->array[i][j].x = Rx;
            terrain->array[i][j].y = Ry;
        }
}
