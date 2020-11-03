main_c: main.c
	gcc -std=c11 -g -static main.c -o main_c

test_c: main_c
	./test_c.sh

main_cpp: main.cpp
	g++ -std=c++11 -g -static main.cpp -o main_cpp

test_cpp: main_cpp
	./test_cpp.sh

clean:
	rm -rf main_c main_cpp

.PHONY: test clean
