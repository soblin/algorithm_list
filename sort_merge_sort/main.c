#include <stdio.h>
#include <stdlib.h>

#define N 100000

int indata[N];
int size = 0;

void load(char **argv){
  char *e;
  for(int i = 0; i < size; ++i){
    indata[i] = atoi(argv[i+1]);
  }
}

void print(int *data, int size){
  for(int i = 0; i < size; ++i){
    printf("%d ", data[i]);
  }
}

int left[N];
int right[N];

void merge(int *data, int start, int mid, int end){
  // merge [start, mid] [mid+1, end]
  int num1 = mid - start + 1;
  int num2 = end - mid;
  for(int i = 0; i < num1; ++i) left[i] = data[start + i];
  for(int j = 0; j < num2; ++j) right[j] = data[mid + 1 + j];
  int pivot1 = 0;
  int pivot2 = 0;

  while(pivot1 <= (num1-1) && pivot2 <= (num2-1)){
    if(left[pivot1] < right[pivot2]){
      data[start + pivot1 + pivot2] = left[pivot1];
      pivot1++;
    }
    else{
      data[start + pivot1 + pivot2] = right[pivot2];
      pivot2++;
    }
  }
  if(pivot1 == num1){
    while(pivot2 != num2){
      data[start + pivot1 + pivot2] = right[pivot2];
      pivot2++;
    }    
  }
  else{
    while(pivot1 != num1){
      data[start + pivot1 + pivot2] = left[pivot1];
      pivot1++;
    }
  }
}

void merge_sort(int *data, int start, int end){
  if(start == end) return;

  int mid = (start + end) / 2;
  merge_sort(data, start, mid);
  merge_sort(data, mid+1, end);

  merge(data, start, mid, end);
}

int main(int argc, char **argv){
  // ./a.out 1 2 3 => argc == 4, argv[1] == "1"
  size = (argc) - 1;
  load(argv);
  merge_sort(indata, 0, size-1);
  print(indata, size);
}
