#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

int randomN(int max) {
	max ++;
	srand(time(NULL));
	printf("%d",rand());
	return rand() % max;
}

char* SearchWord(char* filename, int wordline) {

	FILE* f = fopen(filename, "r");
	if(f==NULL) return NULL;
	char currentword[30] = "";
	int i = 0;
	do { // Pas de protection pour dépassement de fichier
		i++;
		strcpy(currentword,"");
		fscanf(f, "%s\n",currentword);
	}while (i != wordline);
	char foundword[] = "toto";
	return foundword;
}

//char* CreateWord(char* content
