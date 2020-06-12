#include <stdio.h>
#include <stdlib.h>

int array[100];

int main(int argc, char **argv){
  int num = argc - 1;
  for(int i = 0; i < num; ++i)
    array[i] = atoi(argv[i+1]);
  
  for(int i = 0; i < num; ++i)
    printf("%d ", array[i]);

  return 0;
}
