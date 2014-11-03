Test3: Myfunctions.c Myfunctions.h test-ex3.c
	make All
	./test-ex3
	
Test2: Myfunctions.c Myfunctions.h test-ex2.c
	make All
	./test-ex2
	
Test1: Myfunctions.c Myfunctions.h test-ex1.c
	make All
	./test-ex1

All: Myfunctions.c Myfunctions.h test-ex1.c
	gcc -Wall -c test-ex1.c 
	gcc -Wall -c test-ex2.c 
	gcc -Wall -c test-ex3.c 
	gcc -Wall -c Myfunctions.c 
	gcc test-ex1.o Myfunctions.o -o test-ex1
	gcc test-ex2.o Myfunctions.o -o test-ex2
	gcc test-ex3.o Myfunctions.o -o test-ex3
	rm test-ex1.o Myfunctions.o test-ex2.o test-ex3.o
