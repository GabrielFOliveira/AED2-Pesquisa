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

int main(){

    Lista celulas;
   // new_lista(&celulas);
    Celula a;

    FILE *pont_arq;
    pont_arq = fopen("dados.csv", "r");
	char line[1024];
    while (fgets(line, 1024, pont_arq))
	{
		char* tmp = strdup(line);
		strcpy(a.municipio,getfield(tmp,1));
        a.codMunicipio=atol(getfield(tmp,2));
        a.codRegiaoSaude=atol(getfield(tmp,3));
        strcpy(a.nomeRegiaoSaude,getfield(tmp,4));
        a.populacao=atol(getfield(tmp,7));
        a.casosAcumulados=atol(getfield(tmp,8));

        a.obitosAcumulados=atol(getfield(tmp,10));
        //print_celula(a);


        printf("%s\n", tmp);
       // printf("Field 3 would be %s\n", getfield(tmp, 3));

		free(tmp);
	}
}
