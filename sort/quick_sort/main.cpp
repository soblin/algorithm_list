#include <iostream>

int partition(int *array, const int start, const int end){
  int pivot = array[end];
  int insert_pos = start;
  for(int i = start; i <= end; ++i){
    if(array[i] <= pivot){
      int tmp = array[i];
      array[i] = array[insert_pos];
      array[insert_pos] = tmp;
      insert_pos++;
    }
  }
  // finally arra[end] is inserted to `insert_pos`
  return insert_pos - 1;
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
  int array[1000];
  for(int i = 0; i < size; ++i){
    array[i] = atoi(argv[i+1]);
 }

  quick_sort(array, 0, size-1);
  for(int i = 0; i < size; ++i){
    std::cout << array[i] << ' ';
  }
}
