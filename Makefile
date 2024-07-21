all:program

program: main.o 
	gcc build/main.o -std=c99 -g -o build/output

main.o: main.c src/structure.h
	gcc -std=c99 -c main.c -o build/main.o -ggdb -g 

clean:
	rm build/*.o 
	rm build/output
run:
	./build/output
debug:
	gdb ./build/output

test:
	gcc tests/main.c -o build/tests/mainTest
	./build/tests/mainTest
