#include "raise.h"

/**
 * parsing - parse the terrain file
 * @terrain: pointer to global structure
 *
 * Return: success 0 or 1 if anything fails.
 *
 */

int parsing(raise_t *terrain)
{
    FILE *file;
    char *buffer = NULL, *token;
    size_t num = 0;
    int i;
    
    if (terrain->filename == NULL)
    {
        fprintf(stderr, "Invalid file name\n");
        return (1);
    }
    /* Opening file */
    file = fopen(terrain->filename, "r");
    if (file == NULL)
    {
            fprintf(stderr, "Error: Can't open file\n");
            return (1);
    }
    /* Getting Size */
    for (; getline(&buffer, &num, file) != -1; terrain->rows++)
        if (terrain->rows == 0)
        {
            token = strtok(buffer, " \n");
            while (token)
            {
                token = strtok(NULL, " \n");
                terrain->columns++;
            }
        }
    terrain->array = malloc(sizeof(coord *) * terrain->rows);
    if (!terrain->array)
    {
        fprintf(stderr, "Error allocating malloc for Rows\n");
        return (1);
    }
    for (i = 0; i < terrain->rows; i++)
    {
        terrain->array[i] = malloc(sizeof(coord) * terrain->columns);
        if (!terrain->array[i])
        {
            fprintf(stderr, "Error allocating malloc for Columns\n");
            return (1);
        }
    }
    free(buffer);
    fclose(file);
    process_data(terrain);
    return (0);
}
