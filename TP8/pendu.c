#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Myfunctions.h"

void printGuessedWord(char* guessedWord, int wordLength);
void printInterface(char* guessedWord, int wordLength, int tries, int maxTries);
void endGame(int win);

int main() {
	char* randomWord = randomWordInFile("francais.txt"); // Génération du mot aléatoire
	int wordLength = strlen(randomWord);

	char* guessedWord; // Array contenant les lettres trouvées par l'utilisateur
	guessedWord = calloc(sizeof(char),wordLength);

	int i;
 	int maxTries = 11;
 	int tries = 0;
 	int goodTry = 0;
	char letter; // Letter proposed by the user
	int win = 0;

	while(tries <= maxTries) {
		printInterface(guessedWord,wordLength,tries,maxTries);

		printf("Choisissez une lettre :");
		scanf("%s", &letter);
		goodTry = 0;
		for (i = 0; i < wordLength; ++i)
		{
			if(randomWord[i] == letter) {
				guessedWord[i] = letter;
				goodTry = 1;
			}
		}
		if(goodTry == 0) tries += 1;
		//sleep(1);
		if(strcmp(guessedWord,randomWord) == 0) {
			win = 1;
			break;
		}
	}
	endGame(win);

	return 0;
}

void printGuessedWord(char* guessedWord, int wordLength) {
	int i;

	for (i = 0; i < wordLength; ++i)
	{
		if(guessedWord[i] > 64 && guessedWord[i] < 123) {
			printf("%c", guessedWord[i]);
		} else {
			printf("_");
		}
	}
}

void printInterface(char* guessedWord, int wordLength, int tries, int maxTries) {
	printf("\e[1;1H\e[2J");
	printf("------PENDU------\n");
	printf("\n");
	printGuessedWord(guessedWord,wordLength);
	printf("\n");
	printf("\n");		
	printf("Essais : %d / %d\n", tries,maxTries);
	printf("\n");	
}

void endGame(int win) {
	printf("\e[1;1H\e[2J");
	if(win == 1) {
		printf("Vous avez gagné ! :) \n");
		sleep(2);
	} else {
		printf("Vous avez perdu ! :( \n");
		sleep(2);
	}

}