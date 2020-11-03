#include  <iostream>

void insertion_sort(int *array, const int size){
  for(int i = 1; i < size; ++i){
    int val = array[i];
    int pos = 0;
    while(val > array[pos] and pos < i)
      pos++;
    
    if(pos == i){
      // val is larger than any other elem in the left side
      break;
    }
    for(int j = i; j >= pos; j--){
      array[j] = array[j-1];
    }
    array[pos] = val;
  }
}

void print(int *array, int size){
  for(int i = 0; i < size; ++i)
    std::cout << array[i] << ' ';
}

int main(int argc, char **argv){
  int array[1000];
  int n_array = argc - 1;
  for(int i = 0; i < n_array; ++i){
    array[i] = atoi(argv[i+1]);
  }
  insertion_sort(array, n_array);
  print(array, n_array);
}
