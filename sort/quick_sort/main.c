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

int partition(int *data, int start, int end){
  int pivot = data[end];
  int pos = start;
  for(int i = start; i <= end-1; ++i){
    if(data[i] < pivot){
      int tmp = data[pos];
      data[pos] = data[i];
      data[i] = tmp;
      pos++;
    }
  }
  int tmp = data[pos];
  data[pos] = pivot;
  data[end] = tmp;

  return pos;
}

void quick_sort(int *data, int start, int end){
  if(start < end){
    int pivot_pos = partition(data, start, end);

    quick_sort(data, start, pivot_pos-1);
    quick_sort(data, pivot_pos + 1, end);
  }
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  quick_sort(indata, 0, size-1);
  print(indata, size);
}
