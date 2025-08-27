/*Faça a multiplicação de todos os elementos da matriz acima por 7*/

#include <stdio.h>

int main()
{
    int M[3][5] = {1,5,9,2,5,7,4,13,21,6,8,-3,5,7,12};
    
    for(int j = 0; j<5; j++)
    {
        M[0][j] = M[0][j] * 7;
        M[1][j] = M[1][j] * 7;
        M[2][j] = M[2][j] * 7;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
