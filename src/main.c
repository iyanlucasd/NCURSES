#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

// define o valor da tecla enter
#define ENTER 10
int main(void)
{
    // inicialisa a tela (comando inicial)
    initscr();
    // declarar as variaveis
    int altura, largura, inic_y, inic_x;
    // altura da janela
    altura = 10;
    // largura da janela
    largura = 20;
    // posicao inicial das janelas
    inic_y = inic_x = 10;

    // comando pra criar uma nova janela
    WINDOW *win = newwin(altura, largura, inic_y, inic_x);
    // comando pra atualizar o monitor
    refresh();

    // comando cria uma box
    // variaveis janela(ponteiro), posicao inicial e posicao final
    box(win, inic_y, inic_x);
    // comando pra printar na box
    // variaveis janela, linha do texto, coluna do texto, print
    mvwprintw(win, 1, 1, "Hello World!");
    refresh();

    //quando o usuario digitar, pega o char e retorna o valor hex
    //quando nao especificado, vai pra posicao 0,0 (y, x) da janela
    int c = getchar();

    // comando de fechar a janela, termina o programa
    endwin();
    return 0;
}