main_dfs_cpp: main_dfs.cpp
	g++ -std=c++11 -g -static main_dfs.cpp -o main_dfs_cpp

test_dfs_cpp: main_dfs_cpp
	./test_dfs_cpp.sh

main_bfs_cpp: main_bfs.cpp
	g++ -std=c++11 -g -static main_bfs.cpp -o main_bfs_cpp

test_bfs_cpp: main_bfs_cpp
	./test_bfs_cpp.sh

clean:
	rm -rf main_bfs_cpp main_dfs_cpp

.PHONY: test_cpp test_c clean
