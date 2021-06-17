#include "arvore.h"



No *novo_No(Lista* lista) {
 No* novo = (No*) malloc(sizeof(No));
 novo->lista = lista;
 novo->esq = NULL;
 novo->dir = NULL;
 return novo;
}

No* insert(No* no, Lista* lista){
    if (no == NULL)
        return novo_No(lista);
    if (strcmp(lista->celulas->municipio, no->lista->celulas->municipio)<0 )
        no->esq = insert(no->esq, lista);
    else if (strcmp(lista->celulas->municipio, no->lista->celulas->municipio) > 0)
        no->dir = insert(no->dir, lista);
    return no;
}


No* pesquisarArv(No* raiz, char* municipio){
    if (raiz == NULL || strcmp(raiz->lista->celulas->municipio, municipio)== 0)
       return raiz;
    if (strcmp(raiz->lista->celulas->municipio, municipio) < 0)
       return pesquisarArv(raiz->dir, municipio);
    return pesquisarArv(raiz->esq, municipio);
}

void inorder(No* raiz){
    if (raiz != NULL) {
        inorder(raiz->esq);
        printf("%s \n", raiz->lista->celulas->municipio);
        inorder(raiz->dir);
    }
}
//////////////////////


NoCel *novo_NoCel(Celula* celula) {
 NoCel* novo = (NoCel*) malloc(sizeof(NoCel));
 novo->celula = celula;
 novo->esq = NULL;
 novo->dir = NULL;
 return novo;
}

NoCel* insertCel(NoCel* no, Celula* celula){
    if (no == NULL)
        return novo_NoCel(celula);
    if (celula->data < no->celula->data)
        no->esq = insertCel(no->esq, celula);
    else if (celula->data > no->celula->data)
        no->dir = insertCel(no->dir, celula);
    return no;
}


NoCel* pesquisarCel(NoCel* raiz, int data){
    if (raiz == NULL || raiz->celula->data == data)
       return raiz;
    if (raiz->celula->data < data)
       return pesquisarCel(raiz->dir, data);
    return pesquisarCel(raiz->esq, data);
}

void inorderCel(NoCel* raiz){
    if (raiz != NULL) {
        inorderCel(raiz->esq);
        printf("%d \n", raiz->celula->data);
        inorderCel(raiz->dir);
    }
}
