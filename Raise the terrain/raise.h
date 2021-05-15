/*  raise.h
 *  Raise the terrain
 *  Created by Santiago Borgia on 5/15/21.
*/

#ifndef raise_h
#define raise_h
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>

/* Defining MACROS */
#define WIDTH 1000
#define HEIGHT 1000

/* Creating the structures used in all the program */

/**
 * struct coordinates - Store graph coordinates
 * @x: x axis value
 * @y: y axis value
 * @z: z axis value
 *
 * Description: Grid 3D coordinates
 */
typedef struct coordinates
{
    float x;
    float y;
    float z;
} coord;

/**
 * struct global_variables - Global varibales
 * @window: Windows program
 * @renderer: Render program
 * @filename: File name with coordinates
 * @array: Struct containing grid coordinates
 * @columns: grid width
 * @rows: grid height
 *
 * Description: Structure containing global variables
 *
 */
typedef struct global_variables
{
    /*The window variable we'll be rendering to */
    SDL_Window *window;
    /* The renderer contained by the window */
    SDL_Renderer *renderer;
    /*The name of the file */
    char *filename;
    /*The array of coordinates */
    coord **array;
    /* number of columns defined by the file */
    int columns;
    /* number of rows defined by the file */
    int rows;

} raise_t;
/* declareing variable as external */

extern raise_t terrain;

/* Prototypes to handle the program */
int initiate_terrain(raise_t *terrain, char *argv);
int parsing(raise_t *terrain);
void process_data(raise_t *terrain);
int key_events(raise_t *terrain);
void draw_grid(raise_t *terrain);
void cleanup(raise_t *terrain);

#endif /* raise_h */
