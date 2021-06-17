#ifndef  ARVORE_H
#define  ARVORE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

typedef struct No{
    Lista* lista;
    struct No* esq;
    struct No* dir;
}No;


No *novo_No(Lista* lista);
void inorder(No* raiz);
No* insert(No* no, Lista* lista);
No* pesquisarArv(No* raiz, char* municipio);

typedef struct NoCel{
    Celula* celula;
    struct NoCel* esq;
    struct NoCel* dir;
}NoCel;


NoCel *novo_NoCel(Celula* celula);
void inorderCel(NoCel* raiz);
NoCel* insertCel(NoCel* no, Celula* celula);
NoCel* pesquisarCel(NoCel* raiz, int data);


#endif
