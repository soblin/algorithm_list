main_c: main.c
	gcc -std=c11 -g -static main.c -o main_c

test_c: main_c
	./test_c.sh

main_simple_cpp: main_simple.cpp
	g++ -std=c++11 -g -static main_simple.cpp -o main_simple_cpp

test_simple_cpp: main_simple_cpp
	./test_simple_cpp.sh

main_binsearch_cpp: main_binsearch.cpp
	g++ -std=c++11 -g -static main_binsearch.cpp -o main_binsearch_cpp

test_binsearch_cpp: main_binsearch_cpp
	./test_binsearch_cpp.sh

test_py:
	./test_py.sh

clean:
	rm -rf main_simple_cpp main_binsearch_cpp main_c

.PHONY: test_cpp test_c clean
