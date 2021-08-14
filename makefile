hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Program.o -c ./src/Program.c
	gcc -I ./include/ -o ./lib/Test.o -c ./src/Test.c
	gcc -I ./include/ -o ./bin/Test ./lib/Program.o ./src/Test.c

calistir:
	./bin/Test