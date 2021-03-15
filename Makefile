all:
	gcc -g test.c -lcunit -o test.out

clean:
	rm -rf *.out
