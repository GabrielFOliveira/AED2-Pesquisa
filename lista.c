#include "lista.h"


void print_celula(Celula c){
  printf("\nMunicipio: %s \n"
         "Codigo do municipio: %ld\n"
         "Codigo da Regiao de Saude: %d\n"
         "Nome da Regiao de Saude: %s\n"
         "Data: %d/%d/%d\n"
         "Populacao TCU 2019: %ld\n"
         "Casos Acumulados: %ld\n"
         "Casos Novos: %ld\n"
         "Obitos Acumulados: %ld \n\n",
         c.municipio,
         c.codMunicipio,
         c.codRegiaoSaude,
         c.nomeRegiaoSaude,
         (c.data-c.data/100*100),(c.data/100-c.data/10000*100),c.data/10000, //30/05/2021
         c.populacao,
         c.casosAcumulados,
         c.casosNovos,
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

int size_lista(Lista *l){
  return l->n;
}

void print_lista(Lista *l){
 for(int i=0; i<l->n; i++)
    print_celula(l->celulas[i]);
}



