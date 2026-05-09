FLAGS			:= -Wall -Iinclude
LIB				:= include/lib.c
CC				:= gcc-15

all: build 3.3 3.5

build:
	mkdir -p build

3.3:
	$(CC) $(FLAGS) 03/$@.c -o build/$@

3.5:
	$(CC) $(FLAGS) 03/$@.c -o build/$@

clean:
	rm -rf build/

