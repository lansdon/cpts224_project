
CC=gcc
TARGETS=libcma.so ma_group clean #dist
OPTIONS=-g 
#DEBUG=-D'DODEBUG=0' 
all: $(TARGETS)

ma_group: ma 

libcma.so: cma.o
	$(CC) $(OPTIONS) $(DEBUG) -shared cma.o -o libcma.so
ma: ma.o cma.o 
	$(CC) $(OPTIONS) $(DEBUG) ma.o -o ma -L. -lcma
#ma2: ma2.o cma.o 
#	$(CC) $(OPTIONS) $(DEBUG) ma2.o -o ma2 -L. -lcma
cma.o: cma.c cma.h
	$(CC) $(OPTIONS) $(DEBUG) -fPIC -c cma.c -o cma.o
ma.o: ma.c cma.h cma.c 
	$(CC) $(OPTIONS) $(DEBUG) -c ma.c -o ma.o
#ma2.o: ma2.c cma.h cma.c 
#	$(CC) $(OPTIONS) $(DEBUG) -c ma2.c -o ma2.o
clean:
	-rm *.o
#dist:
#	-tar -cf lpage_hw6 *.c *.h make*
