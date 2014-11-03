#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int countWord(char filename[]) {
	FILE* f = fopen(filename, "r"); //Filename is relative to the cwd
	char currentword[30] = "";
	int i = -1; // Compensation pour la dernière lecture nulle
	do {
		strcpy(currentword,"");
		fscanf(f, "%s\n",currentword);
		i++;		
	}while (strcmp(currentword,"") != 0);
	return i;
}
