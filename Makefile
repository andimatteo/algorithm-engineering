FLAGS			:= -Wall -Iinclude
LIB				:= include/lib.c
CC				:= gcc-15

all: build 3.3 3.5 mutual-partitioning build-lcp counting-sort

build:
	mkdir -p build

3.3:
	$(CC) $(FLAGS) 03/$@.c -o build/$@

3.5:
	$(CC) $(FLAGS) 03/$@.c -o build/$@

mutual-partitioning:
	$(CC) $(FLAGS) 06/$@.c -o build/$@

counting-sort:
	$(CC) $(FLAGS) 07/$@.c -o build/$@

build-lcp:
	$(CC) $(FLAGS) 10/$@.c -o build/$@

clean:
	rm -rf build/

