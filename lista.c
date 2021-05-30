#include "lista.h"

void print_celula(Celula c){
  printf("\nMunicipio: %s \n"
         "Codigo do municipio: %ld\n"
         "Codigo da Regiao de Saude: %d\n"
         "Nome da Regiao de Saude: %s\n"
         "Data: %d/%d/%d\n"
         "Populacao TCU 2019: %ld\n"
         "Casos Acumulados: %ld\n"
         "Obitos Acumulados: %ld \n\n",
         c.municipio,
         c.codMunicipio,
         c.codRegiaoSaude,
         c.nomeRegiaoSaude,
         c.data,c.data,c.data,
         c.populacao,
         c.casosAcumulados,
         c.obitosAcumulados);
}
void new_lista(Lista *l){
  l->celulas = (Celula*)malloc(MAX * sizeof(Celula));
  l->n = 0;
}

void add_lista(Lista *l, Celula c){
  if(l->n == MAX){
    printf("Erro: Lista cheia!\n\n");
  }else{
    l->celulas[l->n] = c;
    l->n++;
  }
}


