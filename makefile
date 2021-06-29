##################################################

#ifeq ("x","y")
#makefile
CC= gcc -fopenmp -Wall -Wpedantic -Werror -std=c99
#CC= gcc -Wall -Wpedantic -Werror -std=c99
CFLAGS=-I.
DEPS = headers.h
OBJ = main.o trace.o parser.o out_filename.o \
	fileWriter.o results.o addition.o getfileInfo.o fileprocessor.o \
	display.o matrixConverter.o freeMemory.o scalarMul.o transpose.o \
	structures.o matrixMultiplier.o 
 

PROJECTNAME = mysolution

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

$(PROJECTNAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm
	
.PHONY: clean

clean:
	rm -f $ *.o $(PROJECTNAME)
cleano: 
	rm -f $ *.o 
cleanp:
	rm -f $ $(PROJECTNAME)
myout:
	rm -f $ 22355071*
	
#endif

##################################################
