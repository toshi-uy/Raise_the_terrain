#include "raise.h"

/**
 * initiate_terrain - Initializes the terrain
 * @terrain: pointer to global structure
 *
 * Return: 0 if success or 1 if anything fails or ESC was typed.
 *
 */

int key_events(raise_t *terrain)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || event.type == SDL_SCANCODE_ESCAPE)
            return (1);
/*        if (event.type == SDL_SCANCODE_LEFT)
        {    rotate_grid(terrain, 1);
            break;
        }
        if (event.type == SDL_SCANCODE_RIGHT)
        {
            rotate_grid(terrain, -1);
            break;
        }
 */
        else
            return (0);
    }
    return (0);
}
