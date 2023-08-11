CC = gcc
CFLAGS = -Wall -g
LIB = libbopp.so
OUT = bopp
SRC = Bopp.c

all: $(LIB) $(OUT)

$(LIB): $(SRC)
	echo "Compiling to lib"
	$(CC) $(CFLAGS) -shared -o $(LIB) $(SRC)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT) $(LIB)
