
CC = gcc
CFLAGS = -O3 -g -Wall -DEBUG 
CCCOM=$(CC) $(CFLAGS) -std=c11
LDLIBS = -lmingw32 -lSDLmain -lSDL 
LDFLAGS = -L/mingw/lib 
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
RM = del #-f error makefile : Impossible de trouver C:\_Programmation\C\C_Bresenham\-f
EXEC = scan


all: $(EXEC)

$(EXEC): $(OBJS)
	$(CCCOM) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean 

clean:
	$(RM) *.o *~ *.stackdump *.bak *.makefile *.exe


