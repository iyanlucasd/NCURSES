#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

// fflish(stdin) buffada
#define cleanBuffer while(getchar() != '\n')

void EXERCICIO4()
{
    int valor;
    int par = 0;
    int impar = 0;
    char ver;

    do
    {
        printf("digite um numero\n");
        scanf("%i", &valor);
        if (valor%2 == 0)
        {
            printf("o valor eh par\n");
            if (valor > par)
            {
                par = valor;
            }
            
        }
        else if (valor%2 == 1)
        {
            printf("o valor eh impar\n");
            if (valor > impar)
            {
                impar = valor;
            }
            
        }
        else
        {
            printf("valor invalido!");
        }
        
        cleanBuffer;
        printf("deseja continuar?\n(S/N)\n");
        scanf("%c", &ver);
        ver = toupper(ver);
    } while (ver == 'S');

}
