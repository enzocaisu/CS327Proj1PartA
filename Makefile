all: gensine gendial
gensine: main.c gensnd.c
	gcc -o gensine main.c gensnd.c -I. -lm

gendial: main2.c gensnd.c
	gcc -o gendial main2.c gensnd.c -I. -lm

clean:
	rm gensine gendial gensine.txt gendial.txt
