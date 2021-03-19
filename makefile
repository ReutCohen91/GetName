get_name: get_name.o
	gcc -g -Wall -std=c90 -ansi -pedantic get_name.o -o get_name 

get_name.o: get_name.c
	gcc -c -Wall -std=c90 -ansi -pedantic get_name.c -o get_name.o 
