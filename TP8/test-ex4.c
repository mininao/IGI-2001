#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "Myfunctions.h"

int main() {
	int wordCount = countWord("francais.txt");
	int randomNumber = randomN(wordCount);
	char* randomWord;
	int* histo = Histogram("francais.txt");
	randomWord = searchWord("francais.txt",randomNumber);
	printf("Word : %s \n",randomWord);
	printf("longeur %zu\n",strlen(randomWord));
	printf("Longeur max : %d\n", maxSizeInFile("francais.txt"));

	printf("Histo 1 %d\n", histo[1]);
	printf("Histo 10 %d\n", histo[10]);
	printf("Histo 25 %d\n", histo[25]);
	saveHisto("francais.txt","histo");
	return 0;
}