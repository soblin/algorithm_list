#include <iostream>

enum Order {
  Preorder,
  Inorder,
  Postorder
};

class Node {
 public:
  Node(int val, Node *left=nullptr, Node *right=nullptr){
    val = val;
    left = left;
    right = right;
  }
  int val;
  Node *left;
  Node *right;
};

class Tree {
 public:
  Tree(){
    root = nullptr;
  }
  void insert(int key){
    Node *node = root;
    if(node == nullptr){
      root = new Node(key, nullptr, nullptr);
      root->val = key;
      return;
    }
    
    Node *parent = nullptr;
    while(node != nullptr){
      if(key < node->val){
        parent = node;
        node = node->left;
      }
      else{
        parent = node;
        node = node->right;
      }
    }
    // node == nullptr
    if(key < parent->val){
      parent->left = new Node(key, nullptr, nullptr);
      parent->left->val = key;
    }
    else{
      parent->right = new Node(key, nullptr, nullptr);
      parent->right->val = key;
    }
    return;
  }

  void print(const Node *node, enum Order order){
    if(node == nullptr)
      return;

    if(order == Preorder){
      std::cout << ' ' << node->val;
      print(node->left, order);
      print(node->right, order);
    }
    else if(order == Inorder){
      print(node->left, order);
      std::cout << ' ' << node->val;
      print(node->right, order);
    }
    else{
      print(node->left, order);
      print(node->right, order);
      std::cout << ' ' << node->val;
    }
    return;
  }

  bool find(int key){
    const Node* node = root;
    while(node != nullptr){
      if(node->val == key)
        return true;
      else if(key < node->val)
        node = node->left;
      else
        node = node->right;
    }

    return false;
  }
  Node *root;
};

int main(int argc, char **argv){
  int n_cmd;
  std::cin >> n_cmd;
  std::string cmd;
  int val;
  Tree tree;
  while(n_cmd > 0){
    std::cin >> cmd >> val;
    if(cmd == "insert"){
      tree.insert(val);
    }
    else if(cmd == "find"){
      if(tree.find(val))
        std::cout << "yes\n";
      else
        std::cout << "no\n";
    }
    else{
      tree.print(tree.root, Inorder);
      std::cout << std::endl;
      tree.print(tree.root, Preorder);
    }
    n_cmd--;
  }
}
