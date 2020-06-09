#include <stdio.h>
#include <stdlib.h>

#define N 100000

int indata[N];
int outdata[N];
int count[N];
int size = 0;
int sup = 0;

void load(char **argv){
  char *e;
  for(int i = 0; i < size; ++i){
    indata[i] = atoi(argv[i+2]);
  }
}

void print(int *data, int size){
  for(int i = 0; i < size; ++i){
    printf("%d ", data[i]);
  }
}

void counting_sort(int sup){
  for(int i = 0; i < sup; ++i) count[i] = 0;
  // count the number of each element
  for(int i = 0; i < size; ++i){
    count[indata[i]]++;
  }
  // accumulate the count array
  for(int i = 1; i < sup; ++i){
    count[i] = count[i] + count[i-1];
  }
  for(int i = 0; i < size; ++i){
    int val = indata[i];
    int index = count[val];
    outdata[index-1] = val;
    count[val]--;
  }
}

int main(int argc, char **argv){
  // ./a.out 7 2 5 1 4 2 3 0 => count sort based on '7'
  size = (argc) - 2;
  sup = atoi(argv[1]);
  load(argv);
  counting_sort(sup);
  print(outdata, size);
}
