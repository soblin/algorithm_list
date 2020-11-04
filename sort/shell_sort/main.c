#include <stdio.h>
#include <stdlib.h>

#define N (1000)

int array[N];
int G[N];

void print(const int *array, int size){
  for(int i = 0; i < size; ++i){
    printf("%d ", array[i]);
  }
}

void insertion_sort1(int *array, const int size){
  for(int i = 1; i < size; i++){
    int val = array[i];
    int j = i-1;
    while (j >= 0 && array[j] > val){
      array[j+1] = array[j];
      j--;
    }
    // array[j] < val
    array[j+1] = val;
  }
}

void insertion_sort_step(int *array, const int size, const int step){
  for(int i = step; i < size; ++i){
    // assume array[0] - arrau[step-1] is already sorted
    int j = i - step;
    int val = array[i];
    while(j >= 0 && array[j] > val){
      array[j + step] = array[j];
      j -= step;
    }
    array[j + step] = val;
  }
}

void shell_sort(int *array, int size){
  int n = 1; // the size of G
  int g = 1; // G[0]
  while(g < size){
    G[n-1] = g;
    g = 3 * g + 1;
    n++;
  }

  for(int i = n-1; i >= 0; --i){
    insertion_sort_step(array, size, G[i]);
  }
}

int main(int argc, char **argv){
  int size = argc - 1;
  for(int i = 0; i < size; ++i){
    array[i] = atoi(argv[i+1]);
  }

  shell_sort(array, size);
  print(array, size);
}
