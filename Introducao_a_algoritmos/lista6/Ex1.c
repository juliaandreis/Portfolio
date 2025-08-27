/*Dados os vetores 𝑣1 = [1,5,9,2,5], 𝑣2 = [7,4,13,21,6] e 𝑣3 = [8, −3,5,7,12], faça um programa
que copie o conteúdo dos vetores dados para uma matriz de tamanho 3x5*/

#include <stdio.h>

int main()
{
    int v1[5] = {1,5,9,2,5}, v2[5] = {7,4,13,21,6}, v3[5] = {8,-3,5,7,12};
    
    int M[3][5];
    for(int j = 0; j<5; j++)
    {
        M[0][j] = v1[j];
        M[1][j] = v2[j];
        M[2][j] = v3[j];
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}