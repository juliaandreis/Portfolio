/*5. Uma empresa está monitorando o consumo de água em uma residência ao longo de um mês (30 
dias). Para agilizar o preenchimento dos dados, faça o sorteio de valores entre 100 e 500 litros por 
dia. Escreva um programa que:
a. Sorteie e armazene o consumo diário de água (em litros) em um vetor.
b. Calcule o consumo total do mês.
c. Calcule a média de consumo diário.
d. Imprima o dia em que houve o maior consumo e o menor consumo de água.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int consumo[7], consumoTotal = 0, mediaConsumo, maior = 0, diaMaior, diaMenor, menor = 500;
    
    printf("Consumo diario de água em litros:\n");
    for(int i = 0; i < 7; i++)
    {
        consumo[i] = 100 + rand() % 401;
        printf("Dia %d = %d\n", i+1, consumo[i]);
        consumoTotal = consumoTotal + consumo[i];
        
        if(consumo[i] < menor)
        {
            menor = consumo[i];
            diaMenor = i + 1;
        }
        else if(consumo[i] > maior)
        {
            maior = consumo[i];
            diaMaior = i + 1;
        }
    }
    
    mediaConsumo = consumoTotal / 7;
    
    printf("Consumo total = %d\n", consumoTotal);
    printf("Média diaria de consumo = %d\n", mediaConsumo);
    printf("Dia de menor consumo: %d\n", diaMenor);
    printf("Dia de maior consumo: %d\n", diaMaior);

    return 0;
}