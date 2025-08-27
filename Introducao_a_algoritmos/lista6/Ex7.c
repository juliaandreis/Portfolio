/*Faça um programa que gere uma matriz de inteiros 5x5 e que transforme os números negativos
em positivos e vice-versa.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int mat[5][5], matInversa[5][5];

    printf("MATRIZ ORIGINAL:\n");
    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mat[i][j] = rand() % 21 - 10;
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\nMATRIZ INVERSA\n");
    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            matInversa[i][j] = mat[i][j] * (-1);
            printf("%d\t", matInversa[i][j]);
        }
        printf("\n");
    }

    return 0;
}