#ifndef HASH_H
#define HASH_H
//========================================
#include "lista_hash.h"
#define MAX 10000
//========================================
typedef struct TabelaHash{
  Lista tabela[MAX];
}TabelaHash;

void new_hash(TabelaHash *th){
  for(int i=0; i<MAX; i++)
    new_lista(&th->tabela[i]);
}

void print_tabela_hash(TabelaHash *th){

  for(int i=0; i<MAX; i++){
    //printf("%i\t", i);
    print_lista(&th->tabela[i]);
  }
}

int hash(int chave){
  return chave%MAX;
}
int converter(char *a){
  int soma;
    for ( int i = 0; i < (int) strlen(a); i++ ){
        soma = soma+a[i];
    }
  return soma;
}
void add_hash(TabelaHash *th, Registro dado){
            
  converter(dado.municipio); 

  int pos = hash(dado.municipio);
  add(&th->tabela[pos], dado);

}


Registro pesquisa_hash(TabelaHash *th, int municipio){

  int pos = hash(municipio);

  return pesquisa_lista(&th->tabela[pos],municipio);

}

//========================================
#endif