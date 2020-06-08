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

int find_minimal(int *data, int start, int end){
  int min = data[start];
  int ret = start;
  for(int i = start; i <= end; ++i){
    if(min > data[i]){
      min = data[i];
      ret = i;
    }
  }
  return ret;
}

void simple_selection(int *data, int size){
  for(int i = 0; i <= (size-2); ++i){
    int pivot = find_minimal(data, i+1, size-1);
    if(data[i] > data[pivot]){
      int tmp = data[i];
      data[i] = data[pivot];
      data[pivot] = tmp;
    }
  }
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  simple_selection(indata, size);
  print(indata, size);
}
