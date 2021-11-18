all: forks.o
	gcc -o main forks.o
forks.o: forks.c
	gcc -c forks.c
run:
	./main
