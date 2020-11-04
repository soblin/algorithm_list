#include <iostream>

int array[100];
int step[100];

void print(const int *array, const int size){
  for(int i = 0; i < size; ++i){
    std::cout << array[i] << ' ';
  }
}

void insertion_sort(int *array, const int size, const int step){
  for(int i = step; i < size; ++i){
    int j = i - step;
    int val = array[i];
    while(array[j] > val and j >= 0){
      array[j+step] = array[j];
      j -= step;
    }
    array[j+step] = val;
  }
}

void shell_sort(int *array, const int size){
  int n = 1;
  int g = 1;
  while(g < size){
    step[n-1] = g;
    g = 3 * g + 1;
    n++;
  }

  for(int i = n-1; i >= 0; i--){
    insertion_sort(array, size, step[i]);
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
