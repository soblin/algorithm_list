main_c: main.c
	gcc -std=c11 -g -static main.c -o main_c

test_c: main_c
	./test_c.sh

main_cpp: main.cpp
	g++ -std=c++11 -g -static main.cpp -o main_cpp

test_cpp: main_cpp
	./test_cpp.sh

test_jl:
	./test_jl.sh

clean:
	rm -rf main_cpp main_c

.PHONY: test_cpp test_c clean
