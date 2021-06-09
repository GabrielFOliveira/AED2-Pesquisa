#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include "pesquisa_simples.h"
//#include <errno.h>
const char* getfield(char* line, int num){
	const char* tok;
	char linha[1024];
	strcpy(linha,line);
	for (tok = strtok(linha, ";");
			tok && *tok;
			tok = strtok(NULL, ";\n"))
  {
		if (!--num)
			return tok;
	}
	return NULL;
}

const char* getfieldbar(char* line, int num){
	const char* tok;
	char linha[1024];
	strcpy(linha,line);
	for (tok = strtok(linha, "/");
			tok && *tok;
			tok = strtok(NULL, "/\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}



Celula getarqcelula(char* line){
  char data[10];
	int dia,mes,ano;
  char* tmp = strdup(line);
  Celula a;
  strcpy(a.municipio,getfield(tmp,1));
  a.codMunicipio=atol(getfield(tmp,2));
  a.codRegiaoSaude=atol(getfield(tmp,3));
  strcpy(a.nomeRegiaoSaude,getfield(tmp,4));
  strcpy(data,getfield(tmp,5));
  dia=atoi(getfieldbar(data,1));
  mes=atoi(getfieldbar(data,2))*100;
  ano=atoi(getfieldbar(data,3))*10000;
  a.data=dia+mes+ano;  //20210530
  a.populacao=atol(getfield(tmp,7));
  a.casosAcumulados=atol(getfield(tmp,8));
  a.casosNovos=atol(getfield(tmp,9));
  a.obitosAcumulados=atol(getfield(tmp,10));
  //print_celula(a);
  return(a);
}

void main_seq(){
  Lista lista;
  new_lista(&lista);
  Lista_l lista_l;
  new_lista_l(&lista_l);
  FILE *pont_arq;
  char line[1024];
  pont_arq = fopen("dadosteste.csv", "r");
  fgets(line, 1024, pont_arq);
  char* tmp = strdup(line);
  add_lista(&lista,getarqcelula(tmp));
  print_lista(&lista);
  while (fgets(line, 1024, pont_arq)){
    tmp = strdup(line);
    if(lista_l.listas[lista_l.n].celulas[0].municipio==getfield(tmp,1)){
      add_lista(&lista, getarqcelula(line));
    }
    else{
      add_lista_l(&lista_l,&lista);
      new_lista(&lista);
      add_lista(&lista, getarqcelula(line));
    }


  }
  add_lista_l(&lista_l,&lista);
  print_lista_l(&lista_l);


}

int main(){
  int tipo;
	scanf("%d", &tipo);
	switch ( tipo ) {
    case 1 :
      main_seq();
    break;
    case 2 :
      //main_bin();
    break;
    case 3 :
      //main_arv_bin();
    break;
    case 4 :
      //main_arv_bal();
    break;
    case 5 :
      //main_hash();
    break;

  }
}

