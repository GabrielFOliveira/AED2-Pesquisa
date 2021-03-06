#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "lista.h"
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
  pont_arq = fopen("dados.csv", "r");
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
}
void ler_arquivo_hash(Registro a){

      TabelaHash tabela;

      new_hash(&tabela);

    FILE* arq = fopen("dados.csv", "r");

    char line[1024];
    while (fgets(line, 1024, arq)){

        char data[10];
	int dia,mes,ano;
  char* tmp1;
  char* tmp2;
  char* tmp3;
  char* tmp4;
  char* tmp5;
  char* tmp6;
  char* tmp7;
  char* tmp8;
  char* tmp9;

  tmp1 = strdup(line);tmp2 = strdup(line);tmp3 = strdup(line);tmp4 = strdup(line);tmp5 = strdup(line);tmp6 = strdup(line);tmp7 = strdup(line);tmp8 = strdup(line);tmp9 = strdup(line);

  strcpy(a.municipio,getfield(tmp1,1));
  a.codMunicipio=atol(getfield(tmp2,2));
  a.codRegiaoSaude=atol(getfield(tmp3,3));
  strcpy(a.nomeRegiaoSaude,getfield(tmp4,4));
  strcpy(data,getfield(tmp5,5));
  dia=atoi(getfieldbar(data,1));
  mes=atoi(getfieldbar(data,2))*100;
  ano=atoi(getfieldbar(data,3))*10000;
  a.data=dia+mes+ano;  //20210530
  a.populacao=atol(getfield(tmp6,7));
  a.casosAcumulados=atol(getfield(tmp7,8));
  a.casosNovos=atol(getfield(tmp8,9));
  a.obitosAcumulados=atol(getfield(tmp9,10));

  //print_celula(a);

  free(tmp1);
  free(tmp2);
  free(tmp3);
  free(tmp4);
  free(tmp5);
  free(tmp6);
  free(tmp7);
  free(tmp8);
  free(tmp9);

    add_hash(&tabela,a);

    }
}


int main(){
  setlocale(LC_ALL, "Portuguese_Brasil");
  int tipo;
  char municipio[100];
  int dia, mes, ano, data;
  Lista lista[1000];
  clock_t start_time, end_time;
  double cpu_time_used;
  carrega(lista);
  printf("Lista caregada!\n");
  printf("Digite o nome da cidade desejada:\n");
  gets(municipio);
  printf("Digite a data do registro (formato XX/XX/XXXX)\n");
  scanf("%d/%d/%d",&dia,&mes,&ano);
  mes*=100;
  ano*=10000;
  data=ano+mes+dia;
  while(tipo!=0){
    printf("Selecione a opcao de pesquisa:\n 1) Pesquisa Sequencial\n 2) Pesquisa Binaria\n 3) Arvore Binaria\n 4) Arvore Binaria AVL\n 0 - Para sair\n");
    scanf("%d", &tipo);
    start_time = clock();
    switch ( tipo ) {
      case 1 :;
        Lista* listal;
        listal=pesquisaSequencialMun(lista, municipio, n);
        print_celula(pesquisaSequencialDia(listal->celulas,data,listal->n));
      break;
      case 2 :;
        int i = pesquisaBinariaMun(lista, municipio, n);
        print_celula(lista[i].celulas[pesquisaBinariaData(lista[i].celulas,data, n)]);
      break;
      case 3 :;
        No* root = NULL;
        root = insert(root, &lista[0]);
        for(int i=1;i<n;i++){
            insert(root, &lista[i]);
        }
        No* teste = pesquisarArv(root, municipio);

        NoCel* rootCel = NULL;
        rootCel = insertCel(rootCel, &teste->lista->celulas[0]);
        for(int i=1;i<teste->lista->n;i++){
            insertCel(rootCel, &teste->lista->celulas[i]);
        }
        NoCel* testeCel = pesquisarCel(rootCel,data);
        print_celula(testeCel->celula[0]);

      break;
      case 4 :;
        No_AVL *rootAVL = NULL;
        rootAVL = insertAVL(rootAVL, &lista[0]);
        for(int i=1;i<n;i++){
            rootAVL = insertAVL(rootAVL, &lista[i]);
        }

        No_AVL* testeAVL = pesquisarArv_AVL(rootAVL,municipio);

        NoCel_AVL* rootCelAVL = NULL;
        rootCelAVL = insertNoCelAVL(rootCelAVL, &testeAVL->lista->celulas[0]);
        for(int i=1;i<testeAVL->lista->n;i++){
            rootCelAVL = insertNoCelAVL(rootCelAVL, &testeAVL->lista->celulas[i]);
        }
        NoCel_AVL* testeCelAVL = pesquisarArvNoCel_AVL(rootCelAVL, data);
        print_celula(testeCelAVL->celula[0]);
      break;
      case 5 :  
        Registro c;
        ler_arquivo_hash(c);
        c.municipio = municipio;
        pesquisa_hash(&tabela,c.municipio);
      break;
    }
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo: %f segundos\n",cpu_time_used);
  }
}

