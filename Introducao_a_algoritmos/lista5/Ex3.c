/*Faça um programa para testar se um dado é viciado. Faça o lançamento N vezes (N é um número
lido pelo usuário, pode ser um número bem grande), armazene cada valor que for sorteado em um
array com 6 posições e ao final imprima o percentual do resultado de cada face.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int n, dado, V[6] = {0,0,0,0,0,0};
    float percentual[6];
    
    printf("Digite quantas vezes o dado será lançado: ");
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        dado = rand() % 6 + 1;
        printf("%d\n", dado);
        V[dado-1] = V[dado-1] + 1;
    }
    
    for(int i=0;i<6;i++)
    {
        percentual[i] = (float) V[i] * 100 / n;
        printf("Percentual da face %d = %.2f\n", i+1,percentual[i]);
    }

    return 0;
}