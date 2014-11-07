#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "Myfunctions.h"

int main() {
	char* foundword;
	foundword = searchWord("francais.txt",200);
	printf("longeur %zu\n",strlen(foundword)); // normalement "abattis"
	printf("Word : %s \n",foundword);
	return 0;
}


