#include <iostream>

void counting_sort(const int *array, int *dst, int size, int k){
  int counter[1000];
  for(int i = 0; i <= k; ++i)
    counter[i] = 0;

  for(int i = 0; i < size; ++i)
    counter[array[i]]++;

  for(int i = 0; i <= k; ++i)
    counter[i+1] += counter[i];

  for(int i = 0; i < size; ++i){
    dst[counter[array[i]]-1] = array[i];
    counter[array[i]]--;
  }
}
int main(int argc, char **argv){
  int k;
  int size = argc - 2;
  int array[1000];
  int dst[1000];
  k = atoi(argv[1]);
  for(int i = 0; i < size; ++i)
    array[i] = atoi(argv[i+2]);
  
  counting_sort(array, dst, size, k);
  
  for(int i = 0; i < size; ++i){
    std::cout << dst[i] << ' ';
  }
}
