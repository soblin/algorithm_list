#include <stdio.h>
#include <stdlib.h>

#define NIL -1
#define N 10000

typedef struct Node {
  int parent;
  int left;
  int right;
} Node;

Node Tree[N];
int Depth[N];

void depth(int root, int root_depth){
  Depth[root] = root_depth;
  
  if(Tree[root].left == NIL){
    return;
  }
  else{
    // traverse each child
    int child = Tree[root].left;
    while(child != NIL){
      depth(child, root_depth + 1);
      child = Tree[child].right;
    }
    return;
  }
}

void print(int root){
  printf("node %d: ", root);
  printf("parent = %d, ", Tree[root].parent);
  printf("depth = %d, ", Depth[root]);
  if(Tree[root].parent == NIL)
    printf("root, ");
  else if(Tree[root].left == NIL)
    printf("leaf, ");
  else
    printf("internal node, ");

  printf("[");
  int child = Tree[root].left;
  while(child != NIL){
    printf("%d", child);
    child = Tree[child].right;
    if(child == NIL) break;
    printf(", ");
  }
  printf("]\n");
}

int main(int argc, char **argv){
  int num;
  scanf("%d", &num);

  for(int i = 0; i < num; ++i){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
    Depth[i] = 0;
  }
    
  int id, k, c, prev;
  for(int i = 0; i < num; ++i){
    scanf("%d %d", &id, &k);
    for(int j = 0; j < k; ++j){
      scanf(" %d", &c);
      if(j == 0) Tree[id].left = c;
      else Tree[prev].right = c;
      prev = c;
      Tree[c].parent = id;
    }
  }

  depth(0, 0);
  
  for(int i = 0; i < num; ++i){
    print(i);
  }
}
