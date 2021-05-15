#include "raise.h"

/**
 * initiate_terrain - Initializes the terrain
 * @terrain: pointer to global structure
 * @argv: pointer to argument variables
 *
 * Return: success 0 or 1 if anything fails.
 *
 */

int initiate_terrain(raise_t *terrain, char *argv)
{
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return (EXIT_FAILURE);
    }
    /* Createing the window */
    terrain->window = SDL_CreateWindow("Raise the Terrain!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    /* checking if no window was created */
    if (NULL == terrain->window)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (EXIT_FAILURE);
    }
    /* Creating the renderer */
    terrain->renderer = SDL_CreateRenderer(terrain->window, -1, SDL_RENDERER_ACCELERATED);
    /* checking if no renderer was created */
    if (terrain->renderer == NULL)
        {
            fprintf(stderr, "SDL_CreateRenderer() Error: %s\n", SDL_GetError());
            SDL_DestroyWindow(terrain->window);
            SDL_Quit();
            return (EXIT_FAILURE);
        }
    /* initializing variables */
    terrain->filename = argv;
    terrain->array = NULL;
    terrain->rows = 0;
    terrain->columns = 0;
    return (0);
}

