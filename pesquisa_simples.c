#include "pesquisa_simples.h"

//Estrutura Utilizada para a Pesquisa sequencial e Pesquisa binaria

void new_lista_l(Lista_l *ll){
  ll->listas = (Lista*)malloc(MAX * sizeof(Lista));
  ll->n = 0;
}

// Adiciona uma lista no agrupamento de lista lista_l
void add_lista_l(Lista_l *ll, Lista l){
  if(ll->n == MAX){
    printf("Erro: Lista cheia!\n\n");
  }else{
    ll->listas[ll->n] = l;
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
