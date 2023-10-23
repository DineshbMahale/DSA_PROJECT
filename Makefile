
all: try program

try: data.o hash.o utils.o main.o
	gcc data.o hash.o utils.o main.o -o try

	
hash.o: hash.c hash.h utils.h 
	gcc hash.c -c
	
utils.o: utils.c utils.h hash.h
	gcc utils.c -c
	
data.o: data.c data.h utils.h
	gcc data.c -c
	
main.o: main.c data.h utils.h
	gcc main.c -c

program: data.o hash.o utils.o main.o
	gcc  main.o data.o hash.o utils.o -o program 



clean:
	rm -rvf *.o
