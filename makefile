all:driver.c jobSearch.h stable.o read.o
	gcc -Wall driver.c stable.o read.o

stable.o: stable.c
	gcc -c stable.c

read.o: read.c
	gcc -c read.c
	
clean:
	rm -rf *.o all