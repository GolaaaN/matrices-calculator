mymat: mymat.o mat.o input.o execute.o
	gcc -g -ansi -Wall -pedantic mymat.o input.o mat.o execute.o -o mymat
mymat.o: mymat.c 
	gcc -c -g -ansi -Wall -pedantic mymat.c -o mymat.o
input.o: input.c 
	gcc -c -g -ansi -Wall -pedantic input.c -o input.o
execute.o: execute.c 
	gcc -c -g -ansi -Wall -pedantic execute.c -o execute.o
mat.o: mat.c 
	gcc -c -g -ansi -Wall -pedantic mat.c -o mat.o

