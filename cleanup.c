#include "raise.h"

/**
 * cleanup - cleans any memory left
 * @terrain: pointer to global structure
 *
 */

void cleanup(raise_t *terrain)
{
    int i;
    
    if (terrain->array)
    {   for (i = 0; i < terrain->rows; i++)
            {
                free(terrain->array[i]);
            }
            free(terrain->array);
    }
    if (terrain->renderer)
        SDL_DestroyRenderer(terrain->renderer);
    if (terrain->window)
        SDL_DestroyWindow(terrain->window);
    SDL_Quit();
}
