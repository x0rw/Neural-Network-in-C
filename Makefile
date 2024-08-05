all:program


program: main.o math.o
	gcc build/main.o build/math.o -std=c99 -lm  -g -o build/output

main.o: main.c 
	gcc -c main.c -o build/main.o -ggdb -g 

math.o: src/math.c
	gcc -c src/math.c -o build/math.o -lm -ggdb -g 

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
valgrind:
	valgrind ./build/output
gdb:
	gdb ./build/output
