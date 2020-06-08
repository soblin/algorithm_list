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

void bubble_sort(int *data, int size){
  for(int i = size-2; i >= 0; --i){
    for(int j = 0; j <= i; ++j){
      // swap a[j], a[j+1]
      if(data[j] > data[j+1]){
        int tmp = data[j];
        data[j] = data[j+1];
        data[j+1] = tmp;
      }
    }
  }
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  bubble_sort(indata, size);
  print(indata, size);
}
