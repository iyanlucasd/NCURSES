#ifndef MENU_H
#define MENU_H

// mostra o menu criado
void menu();

// adiciona uma opção ao menu
void menuAddItem(char *op, void (*func)());

#endif
