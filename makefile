mymat: main.o mat.o input.o
	gcc -g -ansi -Wall -pedantic main.o input.o mat.o -o mymat
main.o: main.c 
	gcc -c -g -ansi -Wall -pedantic main.c -o main.o
input.o: input.c 
	gcc -c -g -ansi -Wall -pedantic input.c -o input.o
mat.o: mat.c 
	gcc -c -g -ansi -Wall -pedantic mat.c -o mat.o

