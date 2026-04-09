#include "slide_line.h"

/**
 * reverse - inverse un tableau
 */
void reverse(int *line, size_t size)
{
    size_t i;
    int tmp;

    for (i = 0; i < size / 2; i++)
    {
        tmp = line[i];
        line[i] = line[size - 1 - i];
        line[size - 1 - i] = tmp;
    }
}

/**
 * compress - pousse les nombres vers la gauche
 */
void compress(int *line, size_t size)
{
    size_t i, j = 0;
    int tmp[size];

    for (i = 0; i < size; i++)
        tmp[i] = 0;

    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
            tmp[j++] = line[i];
    }

    for (i = 0; i < size; i++)
        line[i] = tmp[i];
}

/**
 * merge - fusionne les cases identiques
 */
void merge(int *line, size_t size)
{
    size_t i;

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
            i++; // skip pour éviter double merge
        }
    }
}

/**
 * slide_line - fonction principale
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_RIGHT)
        reverse(line, size);

    compress(line, size);
    merge(line, size);
    compress(line, size);

    if (direction == SLIDE_RIGHT)
        reverse(line, size);

    return (1);
}
