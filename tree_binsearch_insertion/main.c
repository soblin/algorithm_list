#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int key;
  struct Node *left, *right, *parent;
} Node;

Node *root, *NIL;

enum Order {
  PreOrder,
  InOrder,
  PostOrder
};

void insert(int val){
  Node *parent = NIL;
  Node *pos = root;
  Node *new;

  new = (Node *)malloc(sizeof(Node));
  new->key = val;
  new->left= NIL;
  new->right  = NIL;

  while(pos != NIL){
    parent = pos;
    if(new->key < pos->key)
      pos = pos->left;
    else
      pos = pos->right;
  }

  new->parent = parent;
  if(parent == NIL)
    root = new;
  else{
    if(new->key < parent->key)
      parent->left = new;
    else
      parent->right = new;
  }
}

void print(Node *root, enum Order order){
  if(order == PreOrder) printf(" %d", root->key);

  if(root->left != NIL)
    print(root->left, order);

  if(order == InOrder) printf(" %d", root->key);

  if(root->right != NIL)
    print(root->right, order);

  if(order == PostOrder) printf(" %d", root->key);
}

int main(int argc, char **argv){
  int num;
  char cmd[128];
  int val;

  scanf("%d", &num);
  for(int i =0; i < num; ++i){
    scanf("%s", cmd);
    if(strcmp(cmd, "insert") ==0 ){
      scanf("%d", &val);
      insert(val);
    }
    else if(strcmp(cmd, "print") ==0 ){
      scanf("%d", &val);
      print(root, InOrder);
      printf("\n");
      print(root, PreOrder);
      printf("\n");
    }
  }

  return 0;
}
