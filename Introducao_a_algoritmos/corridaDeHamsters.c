/*Dois hamsters, cada um em sua bola, estão participando de uma corrida em um tabuleiro de 12 posições,
numeradas de 0 a 12. Ambos os hamsters começam a corrida na posição 0. A cada turno, um número
inteiro é sorteado para determinar o movimento de cada hamster*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int posA = 0,posB = 0;
    int cont = 1;
    srand(time(0));

    printf("Simulação de corrida de hamsters\n");
    printf("Posição inicial Hamster 1: 0\n");
    printf("Posição inicial Hamster 2: 0\n");

    while (posA < 12 && posB <12)
    {
        int a = 1 + rand() % 5;
        if (a == 1)
        {
            posA = posA + 1;
        }
        else if (a == 2)
        {
            posA = posA + 2;
        }
        else if (a == 4)
        {
            posA = posA - 1;
        }
        else if (a == 5)
        {
            posA = posA - 2;
        }
        if(posA < 0)
        {
            posA = 0;
        }
        else if (posA > 12)
        {
            posA = 12;
        }

        int b = 1 + rand() % 5;
        if (b == 1)
        {
            posB = posB + 1;
        }
        else if (b == 2)
        {
            posB = posB + 2;
        }
        else if (b == 4)
        {
            posB = posB - 1;
        }
        else if (b == 5)
        {
            posB = posB - 2;
        }
        if(posB < 0)
        {
            posB = 0;
        }
        else if (posB > 12)
        {
            posB = 12;
        }

        printf("%d° turno:\n", cont);
        printf("Hamster 1: %d\n", posA);
        printf("Hamster 2: %d\n", posB);
        printf("\n");
        cont++;
    }

    if (posA == 12 && posB == 12)
    {
        printf("Houve um empate!");
    }
    else if (posA == 12)
    {
        printf("O hamster 1 venceu!");
    }
    else if (posB == 12)
    {
        printf("O hamster 2 venceu!");
    }

    return 0;
}