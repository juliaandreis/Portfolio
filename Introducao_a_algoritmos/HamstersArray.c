#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> //para usar o tipo booleano (bool)

const int MAX = 5; // consntante não da pra mudar o valor no meio do codigo, diferente de uma variável
// por isso pode ser usada para definir o tamanho de um array

int main()
{
    srand(time(0));
    int posHamsters[MAX];
    bool acabou = false;

    for(int i = 0; i < MAX; i++)
    {
        posHamsters[i] = 0;
    }

    while(acabou == false) //!acabou é igual a acabou == false
    {
        for(int i = 0; i < MAX; i++)
        {
            int a = 1 + rand() % 5;
            if (a == 1)
            {
                posHamsters[i]++;
            }
            else if (a == 2)
            {
                posHamsters[i] = posHamsters[i] + 2;
            }
            else if (a == 4)
            {
                posHamsters[i]--;
            }
            else if (a == 5)
            {
                posHamsters[i] = posHamsters[i] - 2;
            }
            if(posHamsters[i] < 0)
            {
                posHamsters[i] = 0;
            }
            else if (posHamsters[i] > 12)
            {
                posHamsters[i] = 12;
            }
            if (posHamsters[i] >= 12)
            {
                acabou = true;
            }
        }

        //Desenhar o caminho dos hamsters
        for(int i = 0; i < MAX; i++)
        {
            printf("\n Hamster %d: ", i+1);
            for(int j = 0; j < posHamsters[i]; j++)
            {
                printf("* ");
            }
        }
        printf("\n");
        getchar();
    }
    return 0;
}