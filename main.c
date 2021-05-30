#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
//#include <errno.h>
const char* getfield(char* line, int num)
{
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


int main(){

    Lista celulas;
    new_lista(&celulas);
    Celula a;
    FILE *pont_arq;
    pont_arq = fopen("dados.csv", "r");
	char line[1024];
	char data[10];
	int dia,mes,ano;
    while (fgets(line, 1024, pont_arq))
	{
		char* tmp = strdup(line);
		strcpy(a.municipio,getfield(tmp,1));
        a.codMunicipio=atol(getfield(tmp,2));
        a.codRegiaoSaude=atol(getfield(tmp,3));
        strcpy(a.nomeRegiaoSaude,getfield(tmp,4));
        strcpy(data,getfield(tmp,5));
        dia=atoi(getfieldbar(data,1));
        mes=atoi(getfieldbar(data,2))*100;
        ano=atoi(getfieldbar(data,3))*10000;
        a.data=dia+mes+ano;
        a.populacao=atol(getfield(tmp,7));
        a.casosAcumulados=atol(getfield(tmp,8));
        a.obitosAcumulados=atol(getfield(tmp,10));
        print_celula(a);
		free(tmp);
	}
}
