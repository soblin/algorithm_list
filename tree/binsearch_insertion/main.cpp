#include <iostream>

enum Order {
  PreOrder,
  InOrder,
  PostOrder
};

class Node {
 public:
  int key = -1;
  Node* left = nullptr;
  Node * right = nullptr;
  Node(){
    key = -1;
    left = right = nullptr;
  }
};

void insert(Node *root, int val){
  Node *pivot = root;
  Node *parent = nullptr;
  while(pivot != nullptr){
    int key = pivot->key;
    if(val < key){
      parent = pivot;
      pivot = pivot->left;
    }
    else{
      parent = pivot;
      pivot = pivot->right;
    }
  }

  if(val < parent->key){
    pivot = new Node();
    parent->left = pivot;
    pivot->key = val;
  }
  else{
    pivot = new Node();
    parent->right = pivot;
    pivot->key = val;
  }
}

void print(Node *root, Order order){
  if(root == nullptr)
    return;
  
  if(order == PreOrder){
    std::cout << ' ' << root->key;
    print(root->left, order);
    print(root->right, order);
  }
  else if(order == InOrder){
    print(root->left, order);
    std::cout << ' ' << root->key;
    print(root->right, order);
  }
  else{
    print(root->left, order);
    print(root->right, order);
    std::cout << ' ' << root->key;
  }
}

int main(int argc, char **argv){
  int n_cmd;
  std::cin >> n_cmd;
  std::string cmd;
  int val;
  Node root;
  for(int i = 0; i < n_cmd; ++i){
    std::cin >> cmd >> val;
    // only first
    if(i == 0){
      root.key = val;
      continue;
    }
    
    if(cmd == "insert")
      insert(&root, val);
    
    else if(cmd == "print"){
      print(&root, InOrder);
      std::cout << '\n';
      print(&root, PreOrder);
    }
    else
      break;
  }
}
