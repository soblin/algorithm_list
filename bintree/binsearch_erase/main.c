#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum Order {
  PREORDER,
  INORDER,
  POSTORDER
};

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

Node *root;

void print(const Node* root, enum Order order){
  if (root == NULL)
    return;

  if (order == PREORDER){
    printf(" %d", root->val);
    print(root->left, order);
    print(root->right, order);
  }
  else if (order == INORDER){
    print(root->left, order);
    printf(" %d", root->val);
    print(root->right, order);
  }
  else{
    print(root->left, order);
    print(root->right, order);
    printf(" %d", root->val);
  }
}

void insert(int val){
  if (root == NULL){
    root = (Node *)malloc(sizeof(Node));
    root->val = val;
    root->left = root->right = root->parent = NULL;
    return;
  }
  Node *parent = NULL;
  Node *node = root;
  while(node != NULL){
    parent = node;
    node = (val < node->val ?
            node->left :
            node->right);
    
  }

  if(val < parent->val){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    new_node->parent = parent;
    parent->left = new_node;
  }
  else{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = new_node->right = NULL;
    new_node->parent = parent;
    parent->right = new_node;
  }
}

bool find(const Node* node, int key){
  while(node != NULL){
    if(node->val == key) return true;

    if(key < node->val)
      node = node->left;
    else
      node = node->right;
  }
  return false;
}

Node *successor(const Node* node){
  Node *suc = node->right;
  Node *next = suc->left;
  while(next != NULL){
    suc = next;
    next = next->left;
  }
  
  return suc;
}

void delete(int key){
  // first find the key
  Node* iter = root;
  Node* parent = NULL;
  while(iter != NULL){
    if(iter->val == key)
      break;

    parent = iter;
    if(key < iter->val)
      iter = iter->left;
    else
      iter = iter->right;
  }

  if(iter == NULL)
    // not found
    return;

  int n_child = 2;
  if(iter->left == NULL) n_child--;
  if(iter->right == NULL) n_child--;
  if(n_child == 0){
    if(key < parent->val){
      free(iter);
      parent->left = NULL;
    }
    else{
      free(iter);
      parent->right = NULL;
    }
    return;
  }
  if(n_child == 1){
    if(key < parent->val){
      Node *child = (iter->left == NULL)? iter->right : iter->left;
      free(iter);
      parent->left = child;
    }
    else{
      Node *child = (iter->left == NULL)? iter->right : iter->left;
      free(iter);
      parent->right = child;
    }
    return;
  }

  Node *suc = successor(iter);
  iter->val = suc->val;
  suc->parent->left = suc->right;
  free(suc);
  return;
}

int main(){
  int n_cmd;
  scanf("%d", &n_cmd);

  char cmd[32];
  int val;

  //  Node *root = NULL;
  root = NULL;
  while(n_cmd > 0){
    scanf("%s", cmd);
    if(strcmp(cmd, "insert") == 0){
      // insert
      scanf("%d", &val);
      insert(val);
    }
    else if(strcmp(cmd, "find") == 0){
      scanf("%d", &val);
      printf("%s\n", (find(root, val)? "yes" : "no"));
    }
    else if(strcmp(cmd, "print") == 0){
      print(root, INORDER);
      printf("\n");
      print(root, PREORDER);
      printf("\n");
    }
    else if(strcmp(cmd, "delete") == 0){
      scanf("%d", &val);
      delete(val);
    }
    n_cmd--;
  }
}
