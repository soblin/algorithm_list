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

void print(int *data, int size, int pos){
  for(int i = 0; i < size; ++i){
    if(i == pos){
      printf("[%d] ", data[i]);
    }
    else{
      printf("%d ", data[i]);
    }
  }
}

// partition with pivot data[end]
int partition(int *data, int start, int end){
  int pivot = data[end];
  int pos = start;
  // compare [start] - [end-1] with pivot
  for(int i = start; i <= (end-1); ++i){
    if(data[i] < pivot){
      int tmp = data[i];
      data[i] = data[pos];
      data[pos] = tmp;
      pos++;
    }
  }
  int tmp = data[pos];
  data[pos] = pivot;
  data[end] = tmp;

  return pos;
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  int pos = partition(indata, 0, size-1);
  print(indata, size, pos);
}
