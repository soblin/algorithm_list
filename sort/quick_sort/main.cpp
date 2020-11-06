#include <iostream>

int parition(int *array, const int start, const int end){
  int pivot = array[end];
  
}
void quick_sort(int *array, const int start, const int end){
  if(start < end){
    int pivot = partition(array, start, end);
    quick_sort(array, start, pivot-1);
    quick_sort(array, pivot+1, end);
  }
}
int main(int argc, char **argv){
  int size = argc - 1;
  array[1000];
  for(int i = 0; i < size; ++i){
    array[i = atoi(argv[i+1])];
  }

  quick_sort(array, 0, size-1);
  for(int i = 0; i < size; ++i){
    std::cout << array[i] << ' ';
  }
}
