#include "raise.h"

/**
 * draw_grid - function that draws the received grid on the renderer.
 * @terrain: pointer to global structure
 *
 */

void draw_grid(raise_t *terrain)
{
    int i, j;
    float x, y, z;
    float xx, yy, XX, YY;
    float incl = 0.7;
    float Cx, Cy;

    Cx = WIDTH / 2.2;
    Cy = HEIGHT / 3.2;
    
    for (i = 0; i < terrain->rows; i++)
    {
        for (j = 0; j < terrain->columns; j++)
        {
            x = terrain->array[i][j].x;
            y = terrain->array[i][j].y;
            z = terrain->array[i][j].z;
            /* Gets isometric projection of x and y */
            xx = (incl * (x - y)) + Cx;
            yy = ((1 - incl) * (x + y) - z) + Cy;
            
            /* until the last row */
            if (i < terrain->rows - 1)
            {
                /* Takes next X coordinate to draw */
                x = terrain->array[i + 1][j].x;
                y = terrain->array[i + 1][j].y;
                z = terrain->array[i + 1][j].z;
                /* Gets isometric projection of next x and y */
                YY = ((1 - incl) * (x + y) - z) + Cy;
                XX = (incl * (x - y)) + Cx;
                /* Draws the lines between x and y, and the next ones */
                SDL_RenderDrawLine(terrain->renderer, xx, yy, XX, YY);
            }
            
            /* until the last column */
            if (j < terrain->columns - 1)
            {
                /* same for the colums */
                x = terrain->array[i][j + 1].x;
                y = terrain->array[i][j + 1].y;
                z = terrain->array[i][j + 1].z;
                YY = ((1 - incl) * (x + y) - z) + Cy;
                XX = (incl * (x - y)) + Cx;
                SDL_RenderDrawLine(terrain->renderer, xx, yy, XX, YY);
            }
        }
    }
}
