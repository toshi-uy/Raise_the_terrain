/* Including header */
#include "raise.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument variables
 *
 * Return: success or failure.
 *
 */

int main(int argc, char **argv)
{
    /* defining the struct with the global variable */
    raise_t terrain;
    if (argc != 2)
        {
            fprintf(stderr, "Usage: terrain <file>\n");
            return (EXIT_FAILURE);
        }
    if (initiate_terrain(&terrain, argv[1]) != 0)
        return (EXIT_FAILURE);
    if (parsing(&terrain) != 0)
        return (EXIT_FAILURE);
    while ("looping")
    {
        SDL_SetRenderDrawColor(terrain.renderer, 0, 0, 0, 0);
        SDL_RenderClear(terrain.renderer);
        if (key_events(&terrain) == 1)
            break;
        SDL_SetRenderDrawColor(terrain.renderer, 255, 0, 255, 255);
        draw_grid(&terrain);
        SDL_RenderPresent(terrain.renderer);
    }
    
    /* Execute a cleanup */
    cleanup(&terrain);
    return (EXIT_SUCCESS);
}
