all: fork.c
	gcc fork.c

run: all
	./a.out

clean:
	rm -f *~
	rm -f a.out
