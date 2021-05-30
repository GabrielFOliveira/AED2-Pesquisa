#include "pesquisa_simples.h"

//Estrutura Utilizada para a Pesquisa sequencial e Pesquisa binaria
<<<<<<< Updated upstream
void new_lista_l(Lista_l *ll){
=======

void new_lista_l(Lista_l* ll){
>>>>>>> Stashed changes
  ll->listas = (Lista*)malloc(MAX * sizeof(Lista));
  new_lista(ll->listas);
  ll->n = 0;
}

// Adiciona uma lista no agrupamento de lista lista_l
void add_lista_l(Lista_l *ll, Lista *l){
  if(ll->n == MAX){
    printf("Erro: Lista cheia!\n\n");
  }else{
    for(int i=0;i<l->n;i++){
      add_lista(ll->listas, l->celulas[i]);
    }
    ll->n++;
  }
}

int size_lista_l(Lista_l *ll){
  return ll->n;
}

void print_lista_l(Lista_l *ll){
 for(int i=0; i<ll->n; i++)
    printf("%s",ll->listas[i].celulas[0].municipio);
}
