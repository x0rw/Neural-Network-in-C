all:program

program: main.o 
	g++ main.o -o build\output

main.o: main.c src/message.h
	g++ -c main.c -fsanitize=address 

clean:
	rm *.o output