all:program

program: main.o 
	gcc main.o -std=c99 -g -o build\output

main.o: main.c src/message.h
	gcc -std=c99 -c main.c -ggdb -g 

clean:
	rm *.o output
