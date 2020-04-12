#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

// fflish(stdin) buffada
#define cleanBuffer while(getchar() != '\n')

void EXERCICIO5()
{
    int salariominimo = 0;
    float salario;
    float menorsalario = 1045.00;
    int count;

    printf("reajuste salarial\n");
    printf("digite quantos funcionarios estao na firma\n");
    scanf("%i", &count);
    for (int i = 0; i < count; i++)
    {
        printf("digite o seu salario:\t");
        scanf("%f", &salario);
        if (salario <= 1045.00)
        {
            salariominimo++;
            if (salario < menorsalario)
            {
                menorsalario = salario;
            }
            
        }
        
    }
    
    printf("o salario minimo esta em R$1045,00\n");
    printf("existem %i funcionarios com o salario minimo na empresa\n", salariominimo);
    printf("o menor salario eh: %f", menorsalario);

}