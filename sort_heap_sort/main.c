#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 10000

int indata[N];
int size = 0;
int sup = 0;

void load(char **argv){
  for(int i = 0; i < size; ++i){
    indata[i] = atoi(argv[i+1]);
  }
}

void print(int *data, int size){
  for(int i = 0; i < size; ++i){
    printf("%d ", data[i]);
  }
}

void heapify(int *array, int node, const int size){
  assert(node < size);
  // array[0] to array[size-1] exits.
  int left = node * 2 + 1;

  if(left >= size){
    // this node has no children
    heapify(array, node-1, size);
    // I dismissed this return at first and caused error.
    return;
  }

  int flag = -1;
  // -1: current node, 0: left child, 1: right child
  if(left == (size-1)){
    // this node has only left child
    flag = (array[node] >= array[left])? -1 : 0;
  }
  else{
    // this node has two children
    flag = (array[left] >= array[left+1])? 0 : 1;
    flag = (array[node] >= array[left+flag])? -1 : flag;
  }

  if(flag == -1){
    if(node == 0)
      // the heap is balanced
      return;
    else
      heapify(array, node-1, size);
  }
  else{
    // swap data[k] and data[left_ind + flag], and then goto left_ind+flag
    int next_node = left + flag;
    int tmp = array[node];
    array[node] = array[next_node];
    array[next_node] = tmp;
    heapify(array, next_node, size);
  }
}

void heap_sort(int *array, int sz){
  int size = sz;
  while(size > 1){
    int root = (size-2) / 2;
    heapify(array, root, size);
    int tmp = array[0];
    array[0] = array[size-1];
    array[size-1] = tmp;
    size--;
  }
}

int main(int argc, char **argv){
  size = argc - 1;
  load(argv);
  int root = (size - 2) / 2;
  heap_sort(indata, size);
  print(indata, size);
}
