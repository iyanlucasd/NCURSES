    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include <string.h>

// define o valor da tecla enter
#define ENTER 10
// define o valor da tecla Esc
#define ESCAPE 27

// cria uma janela centralizada na tela do terminal
WINDOW *createCentralizeWindow(int lines, int columns);
// imprime um texto centralizado na tela
void printwcentralize(WINDOW *window, int line, char *text);
// cria uma janela com uma mensagem que é passada pelo parametro
int messageBox(char *menssage);

WINDOW *createCentralizeWindow(int lines, int columns)
{
    int windowSizeColum = COLS;
    int windowSizeLine = LINES; 

    // if para limitar tamanho maxino da janela ao tamanho do terminal
    if (lines > windowSizeLine)
    {
        lines = windowSizeLine;
    }
    if (columns > windowSizeColum)
    {
        columns = windowSizeColum;
    }    

    // calculo para centralizar janela 
    windowSizeColum/=2;
    windowSizeLine/=2;
    windowSizeColum -= columns/2;
    windowSizeLine -= lines/2;

    // criação da janela
    WINDOW *window;
    window = newwin(lines, // número de linhas da janela
                    columns, // número de colunas 
                    windowSizeLine, // linha que inicia a janela
                    windowSizeColum); // coluna que inicia a janela

    return window;
}

void printwcentralize(WINDOW *window, int line, char *text)
{
    int maxColumns = getmaxx(window);
    int column;
    // pega o tamanho do texto a ser "imprimido"
    int sizeText = strlen(text);
    // calcula a coluna inicial do texto (onde ele começa)
    column = (maxColumns/2)-(sizeText/2);
    // imprime na tela
    mvwprintw(window, line, column, text);
}

int messageBox(char *message)
{
    int num = strlen(message);
    WINDOW *winbox;
    // cria uma janela centralizada
    winbox = createCentralizeWindow(5, num + 5);
    // cria uma linha ao redor da janela
    box(winbox, ACS_VLINE, ACS_HLINE);
    printwcentralize(winbox, 1, message);

    // cria um "botão de OK"
    wattron(winbox, A_REVERSE);
    printwcentralize(winbox, 3, "| OK |");
    wattroff(winbox, A_REVERSE);

    // atualiza a janela, sem isso não mostra a janela
    wrefresh(winbox);

    // não fecha a janela até o usuario digitar enter
    int key;
    do
    {
        key = getch();
    } while (key != ENTER);
    
    // deleta a janela
    delwin(winbox);

}
int BoxExercicio(char *message)
{
    int num = strlen(message);
    WINDOW *winbox;
    // cria uma janela centralizada
    winbox = createCentralizeWindow(5, num + 5);
    // cria uma linha ao redor da janela
    box(winbox, ACS_VLINE, ACS_HLINE);
    printwcentralize(winbox, 1, message);

    // cria um "botão de OK"
    wattron(winbox, A_REVERSE);
    printwcentralize(winbox, 3, "| OK |");
    wattroff(winbox, A_REVERSE);

    // atualiza a janela, sem isso não mostra a janela
    wrefresh(winbox);

    // não fecha a janela até o usuario digitar enter
    int key;
    do
    {
        key = getch();
    } while (key != ENTER);
    
    // deleta a janela
    delwin(winbox);

}