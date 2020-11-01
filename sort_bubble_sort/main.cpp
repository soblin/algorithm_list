#include <iostream>

void bubble_sort(int *array, int size){
  for(int i = size-1; i >= 0; --i){
    for(int j = 0; j <= i-1; ++j){
      if(array[j] > array[j+1]){
        int tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }
}

void print(int *array, int size){
  for(int i = 0; i < size; ++i)
    std::cout << array[i] << ' ';
}

int main(int argc, char **argv){
  int size = argc-1;
  int array[100];
  for(int i = 0;i < size; ++i)
    array[i] = atoi(argv[i+1]);

  bubble_sort(array, size);
  print(array, size);
}
