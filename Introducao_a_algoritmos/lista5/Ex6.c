/*6. Em um jogo com 5 rodadas e 4 jogadores, cada jogador começa com 0 pontos. Escreva um 
programa que:
a. Crie um vetor de 4 elementos, onde cada posição do vetor representa a pontuação 
acumulada de um jogador.
b. A cada rodada, sorteie a pontuação para cada jogador (valores entre 0 e 100).
c. Atualize o vetor de pontuação acumulada com a soma da pontuação de cada rodada.
d. Ao final de cada rodada, verifique se algum jogador fez mais de 80 pontos e exiba uma 
mensagem de "Rodada de Destaque" para esse jogador.
e. Ao final das 5 rodadas, exiba a pontuação total de cada jogador.
f. Informe qual jogador venceu, ou se houve empate (o jogador com a maior pontuação).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int pontos[4] = {0,0,0,0}, n, vencedor, maior = 0;
    
    for(int i=1; i<=5; i++)
    {
        printf("%d° RODADA:\n", i);
        for(int j=0; j<4; j++)
        {
            n = rand() % 101;
            pontos[j] = pontos[j] + n;
            printf("Jogador %d = %d ", j+1, n);
            if(n > 80)
            {
                printf("RODADA DE DESTAQUE");
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("PONTUACAO FINAL:\n");
    for(int i=0; i<4; i++)
    {
        printf("Jogador %d = %d\n", i+1, pontos[i]);
        if(pontos[i] > maior)
        {
            vencedor = i+1;
            maior = pontos[i];
        }
        else if(pontos[i] == maior)
        {
            printf("Empate entre os jogadores %d e %d", vencedor, i+1);
        }
    }
    printf("\n");
    printf("VENCEDOR: Jogador %d", vencedor);

    return 0;
}
