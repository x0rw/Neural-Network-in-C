all:program

program: main.o 
	gcc build/main.o -std=c99 -g -o build/output

main.o: main.c src/message.h
	gcc -std=c99 -c main.c -o build/main.o -ggdb -g 

clean:
	rm build/*.o output
run:
	./build/output
debug:
	gdb ./build/output
