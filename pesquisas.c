#include "lista.h"
#include "pesquisa_simples.h"
#include <stdbool.h>

void swap(Lista *n1, Lista *n2){
  Lista aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;

}
void quicksortRec(Lista *array, int esq, int dir) {
    int i = esq, j = dir;
    int pivo = array->celulas[(dir+esq)/2].data;
    while (i <= j) {
        while (array->celulas[i].data < pivo) i++;
        while (array->celulas[j].data > pivo) j--;
        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    }
    if (esq < j)  quicksortRec(array, esq, j);
    if (i < dir)  quicksortRec(array, i, dir);
}
//=============================================================================
void quicksort(Lista *array) {
    quicksortRec(array, 0, array->n);
}


//pesquisa sequencial municipio
Lista_l pesquisaSequencialMun(Lista_l *ll, char nome){
    for(int i=0; i<ll->n; i++){
        if(strcmp(nome,ll->listas[i].celulas[0].municipio)==0){
            return ll[i];
        }
    }
}

Lista pesquisaSequencialDia(Lista *l, int data){
    for(int i=0; i<l->n; i++){
        if(data == l->celulas[i].data){
            return l[i];
        }
    }
}
//pesquisa binária para pesquisar o município na lista de listas
void pesquisaBinariaMun(Lista_l *ll, char nome){

    quicksort(ll);

    bool resp = false;

    int dir = ll->n - 1, esq = 0, meio;

    while (esq <= dir){
        meio = (esq + dir) / 2;
    if (strcmp(nome,ll->listas[meio].celulas[0].municipio)==0){
        resp = true;
        esq = ll->n;
    }else if(strcmp(nome,ll->listas[meio].celulas[0].municipio)>0)
    {
        esq = meio + 1;

    } else{
        dir = meio - 1;
    }

    }

}

