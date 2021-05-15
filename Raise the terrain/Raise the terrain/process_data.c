#include "raise.h"

/**
 * process_data - Initializes the terrain
 * @terrain: pointer to global structure
 *
 */

void process_data(raise_t *terrain)
{
    FILE *file;
    char *buffer = NULL, *token;
    int i, j;
    
    /* Opening file */
    file = fopen(terrain->filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file\n");
        return;
    }
    for (i = 0; fgets(buffer, 1024, file) != NULL; i++)
    {
        token = strtok(buffer, " \n");
        for (j = 0; token; j++)
        {
            /* coordenate x */
            terrain->array[i][j].x = (WIDTH / (terrain->columns + 8)) * (i + 1);
            /* coordenate y */
            terrain->array[i][j].y = (HEIGHT / (terrain->rows + 3)) * (j + 1);
            /* altitute z using atof, converting string to float */
            terrain->array[i][j].z = atof(token);
            token = strtok(NULL, " \n");
        }
    }
    fclose(file);
}
