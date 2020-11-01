#include <iostream>

class Node {
 public:
  int key = 0;
  int left = -1;
  int right = -1;
  int parent = -1;
  Node() {
    key = 0;
    left = right = 0;
  }
};

Node Tree[10000];

void preOrder(int root){
  std::cout << ' ' << Tree[root].key;
  int left = Tree[root].left;
  if (left != -1) preOrder(Tree[left].key);
  int right = Tree[root].right;
  if (right != -1) preOrder(Tree[right].key);
}

void inOrder(int root){
  int left = Tree[root].left;
  if (left != -1) inOrder(Tree[left].key);
  std::cout << ' ' << Tree[root].key;
  int right = Tree[root].right;
  if (right != -1) inOrder(Tree[right].key);
}

void postOrder(int root){
  int left = Tree[root].left;
  if (left != -1) postOrder(Tree[left].key);
  int right = Tree[root].right;
  if (right != -1) postOrder(Tree[right].key);
  std::cout << ' ' << Tree[root].key;
}

int main(int argc, char **argv){  
  int n_node;
  std::cin >> n_node;
  for(int i = 0; i < n_node; ++i){
    int key, left, right;
    std::cin >> key >> left >> right;
    // look for key
    Tree[key].key = key;
    
    Tree[i].left = left;
    if (left != -1){
      Tree[left].parent = key;
    }
    
    Tree[key].right = right;
    if (right != -1){
      Tree[right].parent = key;
    }
  }

  int root;
  for(int i = 0; i < n_node; ++i){
    if (Tree[i].parent == -1){
      root = i;
      break;
    }
  }

  std::cout << "Preorder\n";
  preOrder(root);
  std::cout << "\nInorder\n";
  inOrder(root);
  std::cout << "\nPostorder\n";
  postOrder(root);
}
