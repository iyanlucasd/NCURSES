#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

void EXERCICIO1()
{
    float valor;
    int flag;
    do
    {  
        printf("qual o valor do produto?\n");
        scanf("%f", &valor);
        if (valor <= 500.00)
        {
            valor = (valor * (30.00/100.00));
            printf("o produto com desconto eh %f\n", valor);
        }
        else if (valor > 500.00 && valor <=3000.00)
        {
            valor = (valor * (40.00/100.00));
            printf("o produto com desconto eh %f\n", valor);
        }
        else if (valor > 3000.00)
        {
            valor = (valor * (50.00/100.00));
            printf("o produto com desconto eh %f\n", valor);
        }
        else
        {
            printf("opcao invalida!\a\n");
        }
        printf("deseja fazer outra operacao?\nsim (1)\nnao(0)\n");
        scanf("%i", &flag);
    } while (flag != 0);
    printf("saindo do programa...\n");
}