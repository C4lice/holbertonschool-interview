#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - vérifie si une position doit être vide
 */
int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - dessine le sponge
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (is_hole(i, j))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
