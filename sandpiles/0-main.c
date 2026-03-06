#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}
