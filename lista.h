#ifndef  LISTA_H
#define  LISTA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

typedef struct Celula{
    char municipio[100];
    long int codMunicipio;
    int codRegiaoSaude;
    char nomeRegiaoSaude[100];
    int dia;
    int mes;
    int ano;
    long int populacao;
    long int casosAcumulados;
    long int obitosAcumulados;
}Celula;

typedef struct Lista{
    Celula *celulas;
    int n;
}Lista;

void new_lista(Lista *l);
void add_lista(Lista *l, Celula c);
void print_lista(Lista *l);
int size_lista(Lista *l);
void print_celula(Celula c);


#endif
