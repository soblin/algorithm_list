#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NIL -1
#define N 1000

typedef struct Node {
  int parent;
  int left;
  int right;
} Node;

Node Tree[N];
int preOrder[N];
int inOrder[N];
int postOrder[N];

int size = 0;

int find(const int *data, int size, int key){
  // inOrderにおけるkeyの位置
  for(int i = 0; i < size; ++i){
    if(key == data[i]){
      return i;
    }
  }
  return NIL;
}

int pos = 0;

int rec(int l, int r, int parent){
  if(l >= r){
    assert(l == r);
    pos++;
    Tree[inOrder[l]].parent = parent;
    return inOrder[l];
  }
  
  int root = preOrder[pos];
  pos++;
  int m = find(inOrder, size, root);
  int left = rec(l, m-1, root);
  int right = rec(m+1, r, root);

  Tree[root].parent = parent;
  Tree[root].left = left;
  Tree[root].right = right;

  // I was missing this line!!
  return root;
}

void printPostOrder(int root){
  if(Tree[root].left != NIL)
    printPostOrder(Tree[root].left);
  
  if(Tree[root].right != NIL)
    printPostOrder(Tree[root].right);

  printf("%d ", root);
}

int main(int argc, char **argv){
  int num;
  char buf;
  scanf("%d", &num);
  
  for(int i = 0; i < num; ++i){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
  }

  for(int i = 0; i < num; ++i){
    scanf("%d", &preOrder[i]);
  }
  
  for(int i = 0; i < num; ++i){
    scanf("%d", &inOrder[i]);
  }

  /* for(int i = 0; i < num; ++i){ */
  /*   printf("%d ", preOrder[i]); */
  /* } */
  /* printf("\n"); */

  /* for(int i = 0; i < num; ++i){ */
  /*   printf("%d ", inOrder[i]); */
  /* } */
  /* printf("\n"); */
  
  pos = 0;
  size = num;
  rec(0, num-1, -1);
  printPostOrder(0);
  printf("\n");
}
