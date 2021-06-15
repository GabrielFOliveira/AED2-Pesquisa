#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"
#include <locale.h>
#include "arvore.h"
#include "arvoreavl.h"
#include "pesquisa.h"

int n=0; // Quantidade de listas no vetor

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
  return(a);
}

void carrega(Lista *lista){

  for(int i=0;i<1000;i++){
    new_lista(&lista[i]);
  }
  FILE *pont_arq;
  char line[1024];
  pont_arq = fopen("dadosteste.csv", "r");
  fgets(line, 1024, pont_arq);
  char* tmp = strdup(line);
  add_lista(&lista[n],getarqcelula(tmp));
  n++;
  while (fgets(line, 1024, pont_arq)){
    tmp = strdup(line);
    if(strcmp(lista[n-1].celulas->municipio,getfield(tmp,1))==0){
      add_lista(&lista[n-1], getarqcelula(line));
    }
    else{
      add_lista(&lista[n], getarqcelula(line));
      n++;
    }
  }
  for(int i=0;i<n;i++){
//    printf("%s\n",lista[i].celulas->municipio);
      print_lista(&lista[i]);
  }
}


int main(){
  setlocale(LC_ALL, "Portuguese_Brasil");
  int tipo;
  Lista lista[1000];
  carrega(lista);
	scanf("%d", &tipo);
	switch ( tipo ) {
    case 1 :
      print_lista(&lista[pesquisaSequencialMun(lista,"Abadia dos Dourados", n)]);
    break;
    case 2 :
      print_lista(&lista[pesquisaSequencialDia(lista,20200327, n)]);
      //main_bin();
    break;
    case 3 :
      //bubbleSortMun(lista, n);

      //print_lista(lista);
      printf("Resultado pesquisa binaria: \n%s\n", lista[pesquisaBinariaMun(lista,"Santa Luzia", n)].celulas->municipio);
      printf("Resultado pesquisa binaria: \n%s\n", lista[pesquisaBinariaMun(lista,"Santa Luzia", n)].celulas->municipio);

      int i = pesquisaBinariaMun(lista,"Santa Luzia", n);
      print_lista(lista);
      printf("Pos do pesq binaria data %d",pesquisaBinariaData(lista[i].celulas,20210211, n));
      //main_arv_bin();
    break;

    case 4 :;
      //main_arv_bal();

      No* root = NULL;
      root = insert(root, &lista[0]);
      for(int i=1;i<n;i++){
          insert(root, &lista[i]);
      }
      inorder(root);

      No* teste = pesquisarArv(root,"Wenceslau Braz");
      print_lista(teste->lista);


      NoCel* rootCel = NULL;
      rootCel = insertCel(rootCel, &teste->lista->celulas[0]);
      for(int i=1;i<teste->lista->n;i++){
          insertCel(rootCel, &teste->lista->celulas[i]);
      }
      //inorderCel(rootCel);

      NoCel* testeCel = pesquisarCel(rootCel,20210510);
      print_celula(testeCel->celula[0]);

    break;
    case 5 :;
      No_AVL *rootAVL = NULL;
      rootAVL = insertAVL(rootAVL, &lista[0]);
      for(int i=1;i<n;i++){
          rootAVL = insertAVL(rootAVL, &lista[i]);
      }

      //preOrder(rootAVL);
      No_AVL* testeAVL = pesquisarArv_AVL(rootAVL,"Wenceslau Braz");
      //print_lista(testeAVL->lista);


      NoCel_AVL* rootCelAVL = NULL;
      rootCelAVL = insertNoCelAVL(rootCelAVL, &testeAVL->lista->celulas[0]);
      for(int i=1;i<testeAVL->lista->n;i++){
          rootCelAVL = insertNoCelAVL(rootCelAVL, &testeAVL->lista->celulas[i]);
      }
      preOrderNoCel(rootCelAVL);
      NoCel_AVL* testeCelAVL = pesquisarArvNoCel_AVL(rootCelAVL, 20210511);
      print_celula(testeCelAVL->celula[0]);
    break;
  }
}

