/*Uma pessoa está monitorando quantos passos ela dá por dia em uma semana. Escreva um 
programa que:
a. Leia e armazene o número de passos dados em cada um dos 7 dias da semana.
b. Calcule o total de passos dados na semana.
c. Calcule a média diária de passos.
d. Verifique se a pessoa conseguiu atingir a meta de 10.000 passos em algum dos dias. Se sim, 
informe quais dias a meta foi alcançada.*/

#include <stdio.h>

int main()
{
    int passos[7], metaPassos[7] = {0}, totalPassos = 0, mediaPassos, j=0;
    
    printf("Digite a quantidade de passos dada em cada dia:\n");
    for(int i = 0; i < 7; i++)
    {
        printf("Dia %d = ", i+1);
        scanf("%d", &passos[i]);
        totalPassos = totalPassos + passos[i];
        if(passos[i] >= 10000)
        {
            metaPassos[j] = i+1;
            j++;
        }
    }
    
    mediaPassos = totalPassos / 7;
    
    printf("Total de passos = %d\n", totalPassos);
    printf("Média diária de passos = %d\n", mediaPassos);
    if(j > 0)
    {
        printf("Meta de passos atingida nos dias: ");
        int n = 0; 
        do
        {
            printf("%d ", metaPassos[n]);
            n++;
        }while(metaPassos[n] != 0);
    }
    

    return 0;
}