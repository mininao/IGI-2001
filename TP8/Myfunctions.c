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
		fscanf(f, "%s",currentword);
		i++;		
	}while (strcmp(currentword,"") != 0);
	return i;
}

int randomN(int max) {
	max ++;
	srand(time(NULL));
	return rand() % max;
}

char* searchWord(char* filename, int wordline) {
	char* foundword;
	char currentword[30] = "";
	FILE* f = fopen(filename, "r");
	if(f==NULL) return NULL;
	int i = 0;
	do { // Pas de protection pour dépassement de fichier
		i++;
		strcpy(currentword,"");
		fscanf(f, "%s",currentword);
	}while (i != wordline);

	foundword = malloc(strlen(currentword)+1);
	strcpy(foundword,currentword);
	return foundword;
}

char* randomWordInFile(char* filename){
	int wordCount = countWord(filename);
	int randomNumber = randomN(wordCount);
	char* randomWord;
	randomWord = searchWord(filename,randomNumber);
	return randomWord;	
}

int maxSizeInFile(char* filename) {
	char currentword[30] = "";
	FILE* f = fopen(filename, "r");
	if(f==NULL) return NULL;
	int max = 0;
	do { // Pas de protection pour dépassement de fichier
		strcpy(currentword,"");
		fscanf(f, "%s",currentword);
		if(strlen(currentword) > max) max = strlen(currentword);
		//printf(":%s: 	%d\n", currentword,max);
	}while (!feof(f));

	return max;
}

int* Histogram(char* filename) {
	int* histo = malloc((maxSizeInFile(filename) + 1 )* sizeof(int));
	histo[0] = maxSizeInFile(filename);
	char currentword[30] = "";
	int currentLength;
	FILE* f = fopen(filename, "r");
	if(f==NULL) return NULL;	
	while (!feof(f)) { // Pas de protection pour dépassement de fichier
		strcpy(currentword,"");
		fscanf(f, "%s",currentword);
		currentLength = strlen(currentword);
		if(currentLength > 0) histo[currentLength] ++;

	};	
	return histo;
}

void saveHisto(char* fileIn, char* fileOut) {
	int* histo = Histogram(fileIn);
	int i;
    FILE *f;
    f = fopen(fileOut, "w");	
	for (i = 1; i < histo[0] + 1; ++i)
	{
		fprintf(f, "%d\t%d\n", i, histo[i]);
	}
}