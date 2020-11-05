#include <iostream>
#define SENTINEL 1000000

void print(const int *array, int size){
  for(int i = 0 ; i < size; ++i){
    std::cout << array[i] << ' ';
  }
}

void merge(int *array, int *left_buf, int *right_buf, const int from, const int mid, const int to){
  // 0 0 1
  // 1 2 3
  // 1 3 5
  for(int i = 0; i <= (mid - from); ++i) left_buf[i] = array[from+i];
  left_buf[mid-from+1] = SENTINEL;
  for(int i = 0; i < (to-mid); ++i) right_buf[i] = array[mid+i+1];
  right_buf[to-mid] = SENTINEL;

  int i = 0;
  int j = 0;
  for(int k = from; k <= to; ++k){
    if (left_buf[i] < right_buf[j]){
      array[k] = left_buf[i];
      i++;
    }
    else{
      array[k] = right_buf[j];
      j++;
    }
  }
}

void merge_sort(int *array, int *left_buf, int *right_buf, const int from, const int to){
  if (from == to)
    return;
  
  int mid = (from + to) / 2;
  merge_sort(array, left_buf, right_buf, from, mid);
  merge_sort(array, left_buf, right_buf, mid+1, to);
  merge(array, left_buf, right_buf, from, mid, to);
}


int main(int argc, char **argv){
  int size = argc - 1;
  int array[1000];
  int left_buf[1000];
  int right_buf[1000];
  for(int i = 0; i < size; ++i)
    array[i] = atoi(argv[i+1]);

  merge_sort(array, left_buf, right_buf, 0, size-1);
  print(array, size);
}
