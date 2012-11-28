###############################################################################
# Makefile for the rpic-lib
###############################################################################
CC=gcc
CFLAGS=-fPIC -c -Wall
LDFLAGS=-shared

SOURCES=rpic-lib.c lib-juice.c
OBJECTS=$(SOURCES:.cpp=.o)
TARGETS=librpic.so

librpic_objects= rpic-lib.o lib-juice.o

all: $(SOURCES) $(TARGETS)

librpic.so: $(librpic_objects)
	$(CC) $(LDFLAGS) $(librpic_objects) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.so* *.o *~
