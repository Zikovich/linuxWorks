# Usage:
# make		# compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = gcc						# compiler to use

LINKERFLAG = -lm

SRCS := myfemtoshell.c
BINS := myfemtoshell

all: myfemtoshell

myfemtoshell: myfemtoshell.o mycp.o mymv.o myecho.o mypwd.o utils.o
		@echo "Checking.."
		gcc  *.o -o myfemtoshell

myfemtoshell.o: myfemtoshell.c myfemtoshell.h
		@echo "Creating object myfemtoshell.."		
		gcc -c myfemtoshell.c
		
mycp.o: mycp.c mycp.h
		@echo "Creating object mycp.."
		indent -kr mycp.c mycp.h
		gcc -c mycp.c


mymv.o: mymv.c mymv.h
		@echo "Creating object mymv.."
		indent -kr mymv.c mymv.h
		gcc -c mymv.c


myecho.o: myecho.c myecho.h
		@echo "Creating object myecho.."
		gcc -c myecho.c
		

mypwd.o: mypwd.c mypwd.h
		@echo "Creating object mypwd.."
		gcc -c mypwd.c
		
utils.o: utils.c utils.h
		@echo "Creating object mypwd.."		
		gcc -c utils.c
		
clean:
		@echo "Cleaning up..."
		rm -rvf *.o myfemtoshell

indent:
		@echo "Identing all *.c and *.h ..."
		indent -kr *.c *.h
