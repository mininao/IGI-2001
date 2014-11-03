#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "Myfunctions.h"

int main() {
	printf("longeur %d\n",strlen(SearchWord("francais.txt",200))); // normalement "abattis"
	printf("Word : %s \n",SearchWord("francais.txt",200));
	return 0;
}


