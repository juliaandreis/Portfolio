/*Escreva um algoritmo que preenche uma matriz 4x6 com valores inteiros aleatórios entre -10 e
10. Calcule as somas:
a. dos elementos da segunda linha
b. dos elementos da quinta coluna
c. da multiplicação dos elementos da primeira linha pelos elementos da quarta linha
d. dos elementos só das colunas com índices pares
e. dos elementos só das linhas com índices ímpares
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int mat[4][6];

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
        }
        printf("\n");
    }
    printf("\nSoma dos elementos:\n");
    printf("a) da segunda linha: ");
    int linha1 = 0;
    for(int j = 0; j < 6; j++)
    {
        linha1 = linha1 + mat[1][j];
    }
    printf("%d\n", linha1);

    printf("b) dos elementos da quinta coluna: ");
    int coluna4 = 0;
    for (int i = 0; i < 4; i++)
    {
        coluna4 = coluna4 + mat[i][4];
    }
    printf("%d\n", coluna4);

    printf("c) da multiplicação dos elementos da primeira linha pelos elementos da quarta linha: ");
    int multi03 = 0;
    for(int j = 0; j < 6; j++)
    {
        multi03 = multi03 + mat[0][j] * mat[3][j];
    }
    printf("%d\n", multi03);

    printf("d) dos elementos só das colunas com índices pares: ");
    int pares = 0;
    for (int j = 0; j < 6; j++)
    {
        if ((j+1) % 2 == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                pares = pares + mat[i][j];
            }
        }
    }
    printf("%d\n", pares);


    printf("e) dos elementos só das linhas com índices ímpares: ");
    int impares = 0, pare = 0;
    for (int i = 0; i < 4; i++)
    {
        if ((i+1) % 2 != 0)
        {
            for (int j = 0; j < 6; j++)
            {
                impares = impares + mat[i][j];
            }
        }
    }
    printf("%d\n", impares);
    
    return 0;
}