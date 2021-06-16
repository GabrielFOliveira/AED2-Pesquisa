#include "lista.h"
#include <stdbool.h>

void swap(Lista *n1, Lista *n2){
  Lista aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;

}
void swapC(Celula *n1, Celula *n2){
  Celula aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;

}

void bubbleSortData(Celula *vetor, int n) {

  if(n==1)
    return;

  for (int j = 0 ; j < (n-1); j++) {

    if (vetor[j].data>vetor[j+1].data) {
      swapC(&vetor[j], &vetor[j+1]); //se o elemento for maior que o proximo, chama a funcao de troca(swap)
    }

  }


  bubbleSortData(vetor, n-1);
}

void bubbleSortMun(Lista *vetor, int n) {

  if(n==1)
    return;

  for (int j = 0 ; j <n-1; j++) {

    if (strcmp(vetor[j].celulas->municipio,vetor[j+1].celulas->municipio)== 1) {
      swap(&vetor[j], &vetor[j+1]); //se o elemento for maior que o proximo, chama a funcao de troca(swap)
    }

  }


  bubbleSortMun(vetor, n-1);
}
//=============================================================================



//pesquisa sequencial municipio
Lista* pesquisaSequencialMun(Lista *l, char *nome, int n){
    for(int i=0; i<n; i++){
        if(strcmp(nome,l[i].celulas->municipio)==0){
            return &l[i];
        }
    }
    return NULL;
}

Celula pesquisaSequencialDia(Celula* celulas, int data, int n){
    for(int i=0; i<n; i++){
        if(data== celulas[i].data){
            return celulas[i];
        }
    }
}
//pesquisa binária para pesquisar o município no vetor de lista
int pesquisaBinariaMun(Lista *l, char *nome, int n){

    bubbleSortMun(l,n);




    int dir = n - 1, esq = 0, meio;

    while (esq <= dir){
        meio = (esq + dir) / 2;
        if (strcmp(nome,l[meio].celulas[0].municipio)==0){
            esq = n;
            return meio;
        }else if(strcmp(nome,l[meio].celulas[0].municipio)==1)
        {
            esq = meio + 1;

        } else{
            dir = meio - 1;
        }

    }

    return -1;



}

int pesquisaBinariaData(Celula *c, int data, int n){

    bubbleSortData(c,n);

    int dir = n - 1, esq = 0, meio;
    while (esq <= dir){

        meio = (esq + dir) / 2;

        if (c[meio].data==data){
            esq = n;
            return meio;
        }else if(c[meio].data<data)
        {
            esq = meio + 1;

        } else{
            dir = meio - 1;
        }

    }

    return -1;



}

