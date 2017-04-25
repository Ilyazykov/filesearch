CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c RedBlackTree.c PrefixTree.c Tests.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=VKtask5

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
