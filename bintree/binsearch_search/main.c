#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
  int key;
  struct Node *parent;
  struct Node *left;
  struct Node *right;
} Node;

Node *root;
Node *NIL;

enum Order {
  PreOrder,
  InOrder,
  PostOrder
};

Node *newNode(int key){
  Node *new = (Node *)malloc(sizeof(Node));
  new->key = key;
  new->parent = new->left = new->right = NIL;

  return new;
}

void insert(int key){
  Node *cur = root;
  Node *new = newNode(key);

  Node *parent = NIL;
  while(cur != NIL){
    parent = cur;
    if(key < cur->key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  
  new->parent = parent;
  if(parent == NIL)
    root = new;
  else if(key < parent->key)
    parent->left  = new;
  else
    parent->right = new;
}

bool find(const Node *root, int key){
  if(root->key == key) return true;
  if(key < root->key){
    if(root->left == NIL) return false;
    return find(root->left, key);
  }
  else{
    if(root->right == NIL) return false;
    return find(root->right, key);
  }
}

void print(const Node *root, enum Order order){
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
  char buf[32];
  int val;
  scanf("%d", &num);

  for(int i = 0; i < num; ++i){
    scanf("%s", buf);
    if(strcmp(buf, "insert") == 0){
      scanf("%d", &val);
      insert(val);
    }
    else if(strcmp(buf, "find") == 0){
      scanf("%d", &val);
      if(find(root, val)) printf("yes\n");
      else printf("no\n");
    }
    else if(strcmp(buf, "print") == 0){
      print(root, InOrder);
      printf("\n");
      print(root, PreOrder);
      printf("\n");
    }
  }
  return 0;
}
