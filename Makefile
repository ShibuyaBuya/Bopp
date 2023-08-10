CC = gcc
CFLAGS = -Wall -g
LIB = src/libbopp.so
SRC = Bopp.c

all: $(LIB) bopp

$(LIB): $(SRC)
	$(CC) $(CFLAGS) -shared -o $(LIB) $(SRC)

bopp: $(SRC) $(LIB)
	$(CC) $(CFLAGS) -o bopp $(SRC) -L. -lbopp

clean:
	rm -f bopp $(LIB)
