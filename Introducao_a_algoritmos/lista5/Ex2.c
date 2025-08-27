/*Faça um programa que leia 5 valores para dentro de um vetor e imprima o resultado de cada
valor multiplicado pela sua posição no vetor. Por exemplo: 1, 2, 3, 4 e 5 imprimirá na tela 0, 2, 6,
12 e 20.*/

#include <stdio.h>

int main ()
{
    int V[5], resultado;
    for(int i=0; i<5; i++)
    {
        printf("Digite o valor de V[%d]: ", i);
        scanf("%d", &V[i]);
    }
    for(int i=0; i<5; i++)
    {
        resultado = i * V[i];
        printf("%d * %d = %d\n", i, V[i], resultado);
    }


    return 0;
}