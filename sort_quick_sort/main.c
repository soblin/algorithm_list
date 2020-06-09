#include <stdio.h>
#include <stdlib.h>

#define N 100000

int indata[N];
int size = 0;

void load(char **argv){
  char *e;
  for(int i = 0; i < size; ++i){
    indata[i] = atoi(argv[i+1]);
  }
}

void print(int *data, int size){
  for(int i = 0; i < size; ++i){
    printf("%d ", data[i]);
  }
}

void quick_sort(int *data, int start, int end){
  if(start == end)
    return;
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  simple_insertion(indata, size);
  print(indata, size);
}
