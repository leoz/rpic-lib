###############################################################################
# Makefile for the rpic-test
###############################################################################
CC=gcc
CFLAGS=-c -Wall -I..
LDFLAGS=
LIBS=-L.. -lrpic

SOURCES=rpic-test.c
OBJECTS=$(SOURCES:.cpp=.o)
TARGETS=rpic-test

rpictest_objects= rpic-test.o

all: $(SOURCES) $(TARGETS)

rpic-test: $(rpictest_objects)
	$(CC) $(LDFLAGS) $(rpictest_objects) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ rpic-test
