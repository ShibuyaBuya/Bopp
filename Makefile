CC = gcc
CFLAGS = -Wall -g -fPIC
LIB = libbopp.so
OUT = a.o
SRC = Bopp.c

all: $(LIB) $(OUT)

$(LIB): $(SRC)
	echo "Compiling to lib"
	$(CC) $(CFLAGS) -shared $(LIB) $(SRC) -lncurses

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lncurses

clean:
	rm -f $(OUT) $(LIB)
