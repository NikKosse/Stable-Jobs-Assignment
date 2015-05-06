all:driver.c jobSearch.h stable.o read.o
	gcc -g -Wall  driver.c stable.o read.o -o jobMatch

stable.o: stable.c
	gcc -g -c stable.c

read.o: read.c
	gcc -g -c read.c
	
clean:
	rm -rf *.o jobMatch
