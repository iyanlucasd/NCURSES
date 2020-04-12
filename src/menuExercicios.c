#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include <string.h>
#include "ctl-utils.c"
#include "menu.h"
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"
#include "ex5.h"

#define clearBuffer while(getchar() != '\n');
#define BG 1

// cria o menu de exercicios e retorna a opção escolhida pelo usuario
    int menuEX();
    // direciona o usuario para as opções escolhias
    void directEX(int opt);

int menuEX()
{
    // cria uma janela com 30 linhas e 60 colunas 
    // e centraliza ela na tela
    WINDOW *winMenuEX;
    winMenuEX = createCentralizeWindow(15, 50);
    // cria uma borda na tela
    box(winMenuEX, ACS_VLINE, ACS_HLINE);

    printwcentralize(winMenuEX, 1, "MENU PRINCIPAL");

    char *text[6];
    text[0] = "1 - Exercicio 1            ";
    text[1] = "2 - Exercicio 2            ";
    text[2] = "3 - Exercicio 3            ";
    text[3] = "4 - Exercicio 4            ";
    text[4] = "5 - Exercicio 5            ";
    text[5] = "6 - Exercicio 6            ";
    
    // pega a entrada do teclado do usuario
    int key;
    // guarda a opção selecionada
    int selectOption = 0;
    while (1)
    {
        // loop para atualizar as opções do usuario
        for (int i = 0; i < 6; i++)
        {
            // checa qual opção esta setada
            if (i == selectOption)
            {
                wattron(winMenuEX, A_REVERSE);
            }
            // imprime as opções de novo 
            mvwprintw(winMenuEX, i+3, 3, text[i]);
            wattroff(winMenuEX, A_REVERSE);
            wrefresh(winMenuEX);
        }
        // pega a tecla digitada pelo usuario
        key = getch();
        switch (key)
        {
            // caso for seta pra baixo
            case KEY_DOWN:
                // checa se pode descer mais uma opção 
                // se não volta pra cima
                if (selectOption == 5)
                {
                    selectOption = 0;
                }
                else
                {
                    selectOption++;
                }            
                break;
            case KEY_UP:
                //  checa se pode subir mais uma opção 
                // se não volta pra baixo
                if (selectOption == 0)
                {
                    selectOption = 5;
                }
                else
                {
                    selectOption--;
                }
                break;
            default:
                break;
        }
        // se precionar enter sai do loop do while 
        if (key == ENTER)
        {
            break;
        }
    }

    delwin(winMenuEX);
    
    return selectOption;

}

void directEX(int opt)
{
    switch (opt)
    {
        // como utilizar
        case 0:
            EXERCICIO1();
            endwin();
            system("clear");
            break;
        
        // editar turmas
        case 1:
            EXERCICIO2();
            endwin();
            system("clear");
            break;
        
        // correção de prova
        case 2:
            EXERCICIO3();
            endwin();
            system("clear");
            break;
        
        // historico de prova
        case 3:
            EXERCICIO4();
            endwin();
            system("clear");
            break;
        
        // log out
        case 4:
            EXERCICIO5();
            endwin();
            system("clear");
            break;
        
        // fechar programa
        case 5:
            messageBox("Volte sempre!!!");
            break;
    }
}