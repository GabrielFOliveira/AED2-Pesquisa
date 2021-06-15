#ifndef  ARVOREAVL_H
#define  ARVOREAVL_H
#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

typedef struct No_AVL{
    Lista* lista;
    struct No_AVL *esq;
    struct No_AVL *dir;
    int alt;
}No_AVL;

int altura(No_AVL  *N);
int maior(int a, int b);
No_AVL* novoNo_AVL(Lista* lista);
No_AVL *girarDireita(No_AVL *y);
No_AVL *girarEsquerda(No_AVL *x);
int fatorBalanceamento(No_AVL *N);
No_AVL* insertAVL(No_AVL* no, Lista* lista);
void preOrder(No_AVL *root);
No_AVL* pesquisarArv_AVL(No_AVL* raiz, char* municipio);

typedef struct NoCel_AVL{
    Celula* celula;
    struct NoCel_AVL *esq;
    struct NoCel_AVL *dir;
    int alt;
}NoCel_AVL;

int alturaNoCel(NoCel_AVL  *N);
NoCel_AVL* novoNoCel_AVL(Celula* celula);
NoCel_AVL *girarDireitaNoCel(NoCel_AVL *y);
NoCel_AVL *girarEsquerdaNoCel(NoCel_AVL *x);
int fatorBalanceamentoNoCel(NoCel_AVL *N);
NoCel_AVL* insertNoCelAVL(NoCel_AVL* no, Celula* celula);
void preOrderNoCel(NoCel_AVL *root);
NoCel_AVL* pesquisarArvNoCel_AVL(NoCel_AVL* raiz, int data);

#endif
