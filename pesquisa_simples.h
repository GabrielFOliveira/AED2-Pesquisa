#ifndef  PESQUISA_SIMPLES_H
#define  PESQUISA_SIMPLES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10000
#include "lista.h"

//Estrutura Utilizada para a Pesquisa sequencial e Pesquisa binaria

typedef struct Lista_l{
    Lista* listas;
    int n;
}Lista_l;

void new_lista_l(Lista_l *ll);
void add_lista_l(Lista_l *ll, Lista *l);
void print_lista_l(Lista_l *ll);
int size_lista_l(Lista_l *ll);

#endif
