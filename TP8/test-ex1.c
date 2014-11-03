#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "Myfunctions.h"

int main() {
	int nbmots = countWord("francais.txt");
	printf("Nombre de mots : %d \n",nbmots);
	return 0;
}
