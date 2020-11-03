#include <stdio.h>

#define N 1000
#define NIL -1

typedef struct Node {
  int parent;
  int left;
  int right;
} Node;

enum Order {
  PreOrder,
  InOrder,
  PostOrder
};

Node Tree[N];

void print(int root, enum Order order){
  if(Tree[root].left == NIL){
    printf(" %d", root);
    return;
  }

  if(order == PreOrder) printf(" %d", root);
  
  print(Tree[root].left, order);
  if(order == InOrder) printf(" %d", root);
  
  print(Tree[root].right, order);
  if(order == PostOrder) printf(" %d", root);
}

int main(int argc, char **argv){
  int num;
  scanf("%d", &num);

  for(int i = 0; i < num; ++i){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
  }
    
  int id, left, right;
  for(int i = 0; i < num; ++i){
    scanf("%d %d %d", &id, &left, &right);
    Tree[id].left = left;
    Tree[id].right = right;
    if(left != NIL) Tree[left].parent = id;
    if(right != NIL) Tree[right].parent = id;
  }

  enum Order order = PreOrder;
  printf("Preorder\n");
  print(0, order);
  printf("\n");

  order = InOrder;
  printf("Inorder\n");
  print(0, order);
  printf("\n");
  
  order = PostOrder;
  printf("Postorder\n");
  print(0, order);
  printf("\n");
}
