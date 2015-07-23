build:
	gcc -c src/tokenizer.c
	gcc -c src/exec.c
	gcc -o mash src/mash.c tokenizer.o exec.o
	make clean
clean:
	rm -rf *.o
