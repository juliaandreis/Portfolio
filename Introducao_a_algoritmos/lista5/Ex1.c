/*Criar um vetor de 10 números v e inicialize-o sorteando valores de 10 a 90 para cada elemento.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    srand(time(0));
    int v[10];

    for(int i = 0; i < 10; i++)
    {
        v[i] = rand() % 81 + 10;
    }
    //a) imprimir o vetor
    printf("v[10] = ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ",v[i]);
    }
    printf ("\n");
    //b. Verificar se existe o valor 50 neste vetor (apenas dizer se encontrou ou não)
    //c. Verificar o número de ocorrências do valor 50 neste vetor.
    int valor50 = 0;
    for(int i = 0; i < 10; i++)
    {
        if(v[i] == 50)
        {
            valor50 = valor50 + 1;
        }
    }
    if(valor50 > 0)
    {
        printf("Há o valor 50 neste vetor.\n");
        printf("Número de ocorrências do valor 50 no vetor = %d\n", valor50);
    }
    else
    {
        printf("Não há o valor 50 neste vetor.\n");
    }

    //d. Calcular a média dos valores do vetor
    int total = 0;
    float media = 0.0;
    for(int i = 0; i < 10; i++)
    {   
        total = total + v[i];
    }
    media = (float)total / 10;
    printf("Media = %.2f\n", media);

    //e. Encontrar o maior e o menor valor dos elementos do vetor.

    int menor = 90, maior = 0;
    for(int i = 0; i < 10; i++)
    {
        if(v[i] > maior)
        {
            maior = v[i];
        }
        if(v[i] < menor)
        {
            menor = v[i];
        }
    }
    printf("Maior = %d\n", maior);
    printf("Menor = %d\n", menor);
    
    //f. Imprimir a soma e o produto acumulado dos valores dos elementos do vetor
    long double produto = 1;
    for(int i = 0; i < 10; i++)
    {
        produto = produto * v[i];
    }
    printf("Soma = %d\n", total);
    printf("Produto = %ld\n", produto);

    //g. Imprimir o vetor em ordem inversa
    printf("Ordem inversa de v[10] = ");
    for(int i = 9; i >= 0; i--)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    //h. Copiar os elementos em ordem inversa para outro vetor.
    int a[10];
    int i = 9;
    printf("a[10] = ");
    for(int x = 0; x < 10; x++)
    {
        a[x] = v[i];
        printf("%d ", a[x]);
        i--;
    }
    
    //i. Crie outros dois vetores com 10 elementos, vPares e vImpares. Copie para vPares todos os
    //elementos pares e para vImpares todos os elementos ímpares. Depois disso, imprima o
    //conteúdo de vPares e vImpares (OBS.: guarde o número de pares e ímpares para poder
    //acessar os vetores depois).
    int vPares[10], vImpares[10];
    int n = 0, m = 0;
    for(int i = 0; i < 10; i++)
    {
        if (v[i] % 2 == 0)
        {
            vPares[n] = v[i];
            n++;
        }
        else
        {
            vImpares[m] = v[i];
            m++;
        }
    }
    printf("\nvPares = ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", vPares[i]);
    }
    printf("\n");
    printf("vImpares = ");
    for(int i = 0; i < m; i++)
    {
        printf("%d ", vImpares[i]);
    }
    return 0;
}