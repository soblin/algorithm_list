#include <iostream>

int main(int argc, char **argv){
  int size = argc - 1;
  int array[1000];
  for(int i = 0; i < size; ++i){
    array[i] = atoi(argv[i+1]);
  }

  const int pivot = array[size-1];
  int insert_pos = 0;
  for(int i = 0; i < size; ++i){
    if(array[i] <= pivot){
      int tmp = array[i];
      array[i] = array[insert_pos];
      array[insert_pos] = tmp;
      insert_pos++;
    }
  }

  for(int i = 0; i < size; ++i){
    if (i == insert_pos-1){
      printf("[%d] ", array[i]);
    }
    else
      printf("%d ", array[i]);
  }
}
