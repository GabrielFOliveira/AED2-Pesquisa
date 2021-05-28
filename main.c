#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
//#include <errno.h>



const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, ";");
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
        /*a.municipio= getfield(tmp,1);
        a.codMunicipio=getfield(tmp,2);
        a.codRegiaoSaude=getfield(tmp,3);
        a.nomeRegiaoSaude=getfield(tmp,4);
        a.populacao=getfield(tmp,7);
        a.casosAcumulados=getfield(tmp,8);
        a.obitosAcumulados=getfield(tmp,10;);
        void print_celula(a);*/
        printf("Field 3 would be %s\n", getfield(tmp, 4));

		free(tmp);
	}
}
