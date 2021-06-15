#include "arvoreavl.h"

int altura(No_AVL  *N){
    if (N == NULL)
        return 0;
    return N->alt;
}

int maior(int a, int b){
    return (a > b)? a : b;
}

No_AVL* novoNo_AVL(Lista* lista){
    No_AVL* no = (No_AVL*) malloc(sizeof(No_AVL));
    no->lista  = lista;
    no->esq   = NULL;
    no->dir  = NULL;
    no->alt = 1;
    return(no);
}

No_AVL *girarDireita(No_AVL *y){
    No_AVL *x = y->esq;
    No_AVL *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->alt = maior(altura(y->esq), altura(y->dir))+1;
    x->alt = maior(altura(x->esq), altura(x->dir))+1;

    return x;
}

No_AVL *girarEsquerda(No_AVL *x){
    No_AVL *y = x->dir;
    No_AVL *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->alt = maior(altura(x->esq), altura(x->dir))+1;
    y->alt = maior(altura(y->esq), altura(y->dir))+1;

    return y;
}

int fatorBalanceamento(No_AVL *N){
    if (N == NULL)
        return 0;
    return altura(N->esq) - altura(N->dir);
}

No_AVL* insertAVL(No_AVL* no, Lista* lista){
    if (no == NULL)
        return(novoNo_AVL(lista));

    if (strcmp(lista->celulas->municipio, no->lista->celulas->municipio)<0)
        no->esq = insertAVL(no->esq, lista);
    else if (strcmp(lista->celulas->municipio, no->lista->celulas->municipio)>0)
        no->dir = insertAVL(no->dir, lista);
    else
        return no;

    no->alt = 1 + maior(altura(no->esq),altura(no->dir));

    int ftr = fatorBalanceamento(no);

    if (ftr > 1 && strcmp(lista->celulas->municipio, no->esq->lista->celulas->municipio) < 0)
        return girarDireita(no);

    if (ftr < -1 && strcmp(lista->celulas->municipio, no->dir->lista->celulas->municipio) > 0)
        return girarEsquerda(no);

    if (ftr > 1 && strcmp(lista->celulas->municipio, no->esq->lista->celulas->municipio) > 0)
    {
        no->esq =  girarEsquerda(no->esq);
        return girarDireita(no);
    }

    if (ftr < -1 && strcmp(lista->celulas->municipio, no->dir->lista->celulas->municipio) < 0)
    {
        no->dir = girarDireita(no->dir);
        return girarEsquerda(no);
    }
    return no;
}

void preOrder(No_AVL *root){
    if(root != NULL)
    {
        printf("%s ", root->lista->celulas->municipio);
        preOrder(root->esq);
        preOrder(root->dir);
    }
}

No_AVL* pesquisarArv_AVL(No_AVL* raiz, char* municipio){
    if (raiz == NULL || strcmp(raiz->lista->celulas->municipio, municipio)== 0)
       return raiz;
    if (strcmp(raiz->lista->celulas->municipio, municipio) < 0)
       return pesquisarArv_AVL(raiz->dir, municipio);
    return pesquisarArv_AVL(raiz->esq, municipio);
}

////////////////////////

int alturaNoCel(NoCel_AVL  *N){
    if (N == NULL)
        return 0;
    return N->alt;
}


NoCel_AVL* novoNoCel_AVL(Celula* celula){
    NoCel_AVL* no = (NoCel_AVL*) malloc(sizeof(NoCel_AVL));
    no->celula  = celula;
    no->esq   = NULL;
    no->dir  = NULL;
    no->alt = 1;
    return(no);
}

NoCel_AVL *girarDireitaNoCel(NoCel_AVL *y){
    NoCel_AVL *x = y->esq;
    NoCel_AVL *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->alt = maior(alturaNoCel(y->esq), alturaNoCel(y->dir))+1;
    x->alt = maior(alturaNoCel(x->esq), alturaNoCel(x->dir))+1;

    return x;
}

NoCel_AVL *girarEsquerdaNoCel(NoCel_AVL *x){
    NoCel_AVL *y = x->dir;
    NoCel_AVL *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->alt = maior(alturaNoCel(x->esq), alturaNoCel(x->dir))+1;
    y->alt = maior(alturaNoCel(y->esq), alturaNoCel(y->dir))+1;

    return y;
}

int fatorBalanceamentoNoCel(NoCel_AVL *N){
    if (N == NULL)
        return 0;
    return alturaNoCel(N->esq) - alturaNoCel(N->dir);
}

NoCel_AVL* insertNoCelAVL(NoCel_AVL* no, Celula* celula){
    if (no == NULL)
        return(novoNoCel_AVL(celula));

    if (celula->data < no->celula->data)
        no->esq = insertNoCelAVL(no->esq, celula);
    else if (celula->data > no->celula->data)
        no->dir = insertNoCelAVL(no->dir, celula);
    else
        return no;

    no->alt = 1 + maior(alturaNoCel(no->esq),alturaNoCel(no->dir));

    int ftr = fatorBalanceamentoNoCel(no);

    if (ftr > 1 && celula->data < no->esq->celula->data)
        return girarDireitaNoCel(no);

    if (ftr < -1 && celula->data > no->dir->celula->data)
        return girarEsquerdaNoCel(no);

    if (ftr > 1 && celula->data > no->esq->celula->data)
    {
        no->esq =  girarEsquerdaNoCel(no->esq);
        return girarDireitaNoCel(no);
    }

    if (ftr < -1 && celula->data < no->dir->celula->data)
    {
        no->dir = girarDireitaNoCel(no->dir);
        return girarEsquerdaNoCel(no);
    }
    return no;
}

void preOrderNoCel(NoCel_AVL *root){
    if(root != NULL)
    {
        printf("%d ", root->celula->data);
        preOrderNoCel(root->esq);
        preOrderNoCel(root->dir);
    }
}

NoCel_AVL* pesquisarArvNoCel_AVL(NoCel_AVL* raiz, int data){
    if (raiz == NULL || raiz->celula->data == data)
       return raiz;
    if (raiz->celula->data < data)
       return pesquisarArvNoCel_AVL(raiz->dir, data);
    return pesquisarArvNoCel_AVL(raiz->esq, data);
}
