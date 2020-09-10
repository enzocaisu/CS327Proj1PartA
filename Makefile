all: main main2
main: main.c gensnd.c
	gcc -o main main.c gensnd.c -I. -lm

main2: main2.c
	gcc -o main2 main2.c

clean:
	rm main main2
