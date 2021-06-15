#include "lista.h"
#include <stdbool.h>

void swap(Lista *n1, Lista *n2);
void swapC(Celula *n1, Celula *n2);
void bubbleSortData(Celula *vetor, int n);
void bubbleSortMun(Lista *vetor, int n);
int pesquisaSequencialMun(Lista *l, char *nome, int n);
int pesquisaSequencialDia(Lista *l, int data, int n);
int pesquisaBinariaMun(Lista *l, char *nome, int n);
int pesquisaBinariaData(Celula *c, int data, int n);
