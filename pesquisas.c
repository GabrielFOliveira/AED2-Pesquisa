#include "lista.h"
//#include "pesquisa_simples.h"
#include <stdbool.h>

void swap(Lista *n1, Lista *n2){
  Lista aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;

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
int pesquisaSequencialMun(Lista *l, char *nome, int n){
    for(int i=0; i<n; i++){
        if(strcmp(nome,l[i].celulas->municipio)==0){
            return i;

        }
    }
    return -1;
}

int pesquisaSequencialDia(Lista *l, int data, int n){
    for(int i=0; i<l->n; i++){
        if(data== l->celulas[i].data){
            return i;
        }
    }
    return -1;
}
//pesquisa bin�ria para pesquisar o munic�pio no vetor de lista
int pesquisaBinariaMun(Lista *l, char *nome, int n){



    bubbleSortMun(l,n);



    bool resp = false;

    int dir = n - 1, esq = 0, meio;

    while (esq <= dir){
        meio = (esq + dir) / 2;
        if (strcmp(nome,l[meio].celulas[0].municipio)==0){
            resp = true;
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

