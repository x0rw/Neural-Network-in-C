all:program


program: main.o math.o structure.o core.o neural_network.o
	gcc build/main.o build/math.o build/structure.o build/core.o build/neural_network.o -std=c99 -lm  -g -o bin/main

main.o: main.c 
	gcc -c main.c -o build/main.o -ggdb -g 

math.o: src/math.c
	gcc -c src/math.c -o build/math.o -lm -ggdb -g 

core.o: src/core.c
	gcc -c src/core.c -o build/core.o -lm -ggdb -g

structure.o: src/structure.c
	gcc -c src/structure.c -o build/structure.o -lm -ggdb -g

neural_network.o: src/neural_network.c
	gcc -c src/neural_network.c -o build/neural_network.o -lm -ggdb -g


clean:
	rm build/*.o 
	rm bin/*
run:
	./bin/main
debug:
	gdb ./bin/main

test:
	gcc tests/main.c -o build/tests/mainTest
	./build/tests/mainTest
valgrind:
	valgrind ./bin/main
gdb:
	gdb ./bin/main
