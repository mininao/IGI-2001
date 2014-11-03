Test: Myfunctions.c Myfunctions.h test-ex1.c
	make All
	./test-ex1

All: Myfunctions.c Myfunctions.h test-ex1.c
	gcc -Wall -c test-ex1.c 
	gcc -Wall -c Myfunctions.c 
	gcc test-ex1.o Myfunctions.o -o test-ex1
	rm test-ex1.o Myfunctions.o
