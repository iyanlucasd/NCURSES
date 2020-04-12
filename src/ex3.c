#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
//fflush(stdin) buffada
#define cleanBuffer while (getchar() != '\n')
void COPRIMO(int x, int y)
{
    
    for (int i = 2; i < 10; i++)
    {
        if (x%i==0 && y%i==0)
        {
            printf("os numeros nao sao coprimos\n");
            break;
        }
        else
        {
            printf("os numeros sao coprimos\n");
            
            
        }
        
    }
    

}
void EXERCICIO3()
{
    int x;
    int y;


    printf("verifique se o numero eh primo?\n");
    printf("digite o primeiro numero\n");
    scanf("%i", &x);
    printf("digite o segundo numero\n");
    scanf("%i", &y);

    if (x % 2 == 0 && x == (y+1))
    {
        printf("os numeros sao coprimos\n");
    }
    else if (x % 2 == 1 && x == (y+2))
    {
        printf("os numeros sao coprimos\n");   
    }
    else
    {
        COPRIMO(x, y);
    }
    
    
}
