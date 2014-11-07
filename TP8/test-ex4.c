#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "Myfunctions.h"

int main() {
	int wordCount = countWord("francais.txt");
	int randomNumber = randomN(wordCount);
	char* randomWord;
	randomWord = searchWord("francais.txt",randomNumber);
	printf("Word : %s \n",randomWord);
	printf("longeur %zu\n",strlen(randomWord));
	return 0;
}