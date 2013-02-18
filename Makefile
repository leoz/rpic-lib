###############################################################################
#  Copyright (C) 2012 - 2013, Leonid Zolotarev
#
#  Licensed under the terms of the BSD license, see file COPYING
#  for details.
#
#  Raspberry Pi Car Library
#
#  Makefile for the rpic-lib
#
###############################################################################

uname_M := $(shell sh -c 'uname -m 2>/dev/null || echo not')

###############################################################################

CC=gcc
CFLAGS=-fPIC -c -Wall
LDFLAGS=-shared

ifeq ($(uname_M),armv6l)
    SOURCES=rpic-lib.c juice/lib-juice.c
    librpic_objects= rpic-lib.o juice/lib-juice.o
else
    SOURCES=rpic-lib.c
    librpic_objects= rpic-lib.o
endif

OBJECTS=$(SOURCES:.cpp=.o)
TARGETS=librpic.so

all: $(SOURCES) $(TARGETS)

librpic.so: $(librpic_objects)
	$(CC) $(LDFLAGS) $(librpic_objects) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ *.so*
	rm -f juice/*.o juice/*~
	rm -f test/*.o test/*~ test/rpic-test

###############################################################################

.PHONY: print_vars

print_vars:
	echo $(uname_M)

###############################################################################

