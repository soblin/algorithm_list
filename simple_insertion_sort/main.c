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

void insert(int *data, int start, int end, int val){
  int pos = start;

  while(data[pos] < val && pos <= end)
    pos++;

  if(pos == (end+1)){
    data[pos] = val;
    return;
  }
  
  for(int i = end; i >= pos; --i){
    data[i+1] = data[i];
  }

  data[pos] = val;
}

void simple_insertion(int *data, int size){
  for(int i = 0; i <= size-2; ++i){
    int val = data[i+1];
    insert(data, 0, i, val);
  }
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  simple_insertion(indata, size);
  print(indata, size);
}
