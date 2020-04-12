#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

void EXERCICIO2()
{
    int nota;
    int maiornota = 0;
    int menornota = 100;
    int flag = 0;

        do
        {
            printf("qual a nota do aluno?\n");
            scanf("%i", &nota);
            if (nota >=0 && nota <60)
            {
                printf("aluno reprovado!\n");
                if (nota > maiornota)
                {
                    maiornota = nota;
                }
                
            }
            else if (nota >= 60 && nota <= 100)
            {
                printf("aluno aprovado!\n");
                if (nota < menornota)
                {
                    menornota = nota;
                }
            }
            else if (nota == -1)
            {
                printf("saindo do programa\n");
                flag++;
            }
            else
            {
                printf("valor invalido\n");
            }
        } while (flag == 0);
    
}
