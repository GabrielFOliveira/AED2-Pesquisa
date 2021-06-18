#ifndef  LISTA_H
#define  LISTA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//========================================
typedef struct Registro{
    char municipio[100];
    long int codMunicipio;
    int codRegiaoSaude;
    char nomeRegiaoSaude[100];
    int data;
    long int populacao;
    long int casosAcumulados;
    long int casosNovos;
    long int obitosAcumulados;
}Registro;

void print_registro(Registro c){

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
//========================================
typedef struct Celula{
  Registro dado;
  struct Celula *prox;
}Celula;

Celula *new_celula(Registro dado){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->dado = dado;
  tmp->prox = NULL;

  return tmp;
}

//========================================
typedef struct Lista{
  Celula *inicio;
  Celula *fim;
  int tam;
}Lista;
//========================================
void new_lista(Lista *l){

  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  tmp->prox = NULL;

  l->inicio = l->fim = tmp;
  l->tam = 0;
}
//========================================
void add(Lista *l, Registro dado){

  Celula *tmp = new_celula(dado);

  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
}
//========================================

void print_lista(Lista *l){

  Celula *tmp = l->inicio->prox;

  //printf("[%d] ", l->tam);

  while(tmp != NULL){
    print_registro(tmp->dado);
    tmp = tmp->prox;
  }

  printf("\n");
}

Registro pesquisa_lista(Lista *l, char *municipio ){

    Celula *tmp = l->inicio->prox;

    while(tmp != NULL){
      if(tmp->dado->municipio == municipio)
        return tmp->dado;

      tmp = tmp->prox;
    }
    /*    
    Registro a;

    if(a.codMunicipio == -1){
       printf("Não existe registro");
    }
    */
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


    return a;
}


//========================================
#endif