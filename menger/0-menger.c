#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: the number of level
 *
 * Return: NOTHING
 */
void menger(int level)
{
	int x;
	int y;
	int size = (int)pow(3, level);
	int hole = 0;

	if (level >= 0)
	{
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size ; y++)
			{
				hole = 0;
				int tx = x;
				int ty = y;

				while (tx > 0 || ty > 0)
				{
					if (tx % 3 == 1 && ty % 3 == 1)
					{
						hole = 1;
						break;
					}
					tx /= 3;
					ty /= 3;
				}
				if (hole)
					printf(" ");
				else
					printf("#");
			}
			printf("\n");
		}
	}
}
