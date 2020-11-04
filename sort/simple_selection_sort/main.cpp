#include <iostream>

int array[1000];

int find_minimum(const int *array, const int from, const int to){
  int min_ind = from;
  int min = array[from];
  for(int j = from; j <= to; ++j){
    if(array[j] < min){
      min = array[j];
      min_ind = j;
    }
  }

  return min_ind;
}

void simple_selection_sort(int *array, const int size){
  for(int i = 1; i <= size-1; ++i){
    // find the minimum from [i, size)]
    int min = find_minimum(array, i, size-1);
    if(array[i-1] > array[min]){
      int tmp = array[i-1];
      array[i-1] = array[min];
      array[min] = tmp;
    }
  }
}

void print(const int *array, const int size){
  for(int  i = 0; i < size; ++i){
    std::cout << array[i] << ' ';
  }
}

int main(int argc, char **argv){
  int size = argc - 1;
  for(int i = 0; i < size; ++i){
    array[i] = atoi(argv[i+1]);
  }

  simple_selection_sort(array, size);

  print(array, size);
}
