/*Encontre o maior e o menor valor da matriz gerada no exercício anterior*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int mat[4][6], maior = -10, menor = 10;

    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mat[i][j] = rand() % 21 - 10;
        }
    }
    printf("Matriz gerada:\n");
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            printf("%d\t", mat[i][j]);
            if(mat[i][j] > maior)
            {
                maior = mat[i][j];
            }
            else if (mat[i][j] < menor)
            {
                menor = mat[i][j];
            }
        }
        printf("\n");
    }
    printf("\nMaior = %d\n", maior);
    printf("Menor = %d\n", menor);

    return 0;
}