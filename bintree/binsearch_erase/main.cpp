#include <iostream>
#include <cassert>

enum Order {
  Preorder,
  Inorder,
  Postorder
};

class Node {
 public:
  Node(int val, Node *left, Node *right, Node *parent){
    val = val;
    left = left;
    right = right;
    parent = parent;
  }
  int val = 0;
  Node *left;
  Node *right;
  Node *parent;
};

Node *successor(Node *node){
  Node *suc = node->right;
  Node *next = suc->left;
  while(next != nullptr){
    suc = next;
    next = next->left;;
  }

  return suc;
}

class Tree {
 public:
  Tree(){
    root = nullptr;
  }
  void insert(int key){
    Node *node = root;
    if(node == nullptr){
      root = new Node(key, nullptr, nullptr, nullptr);
      root->val = key;
      root->left = root->right = nullptr;
      root->parent = nullptr;
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
      Node *new_node = new Node(key, nullptr, nullptr, parent);
      new_node->val = key;
      new_node->left = new_node->right = nullptr;
      new_node->parent = parent;
      parent->left = new_node;;
    }
    else{
      Node *new_node = new Node(key, nullptr, nullptr, parent);
      new_node->val = key;
      new_node->left = new_node->right = nullptr;
      new_node->parent = parent;
      parent->right = new_node;;
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

  void erase(int val){
    Node *node = findNode(val);
    if(node == nullptr){
      // do nothing
      return;
    }
    // case the number of children
    int n_child = 2;
    if(node->left == nullptr) n_child--;
    if(node->right == nullptr) n_child--;
    Node *parent = node->parent;

    assert(node->val == val);
    if(n_child == 0){
      if(val < parent->val){
        parent->left = nullptr;
        free(node);
      }
      else{
        parent->right = nullptr;
        free(node);
      }
      return;
    }
    else if(n_child == 1){
      if(val < parent->val){
        Node *child = (node->left == nullptr)? node->right : node->left;
        parent->left = child;
        child->parent = parent;
        free(node);
      }
      else{
        Node *child = (node->left == nullptr)? node->right : node->left;
        parent->right = child;
        child->parent = parent;
        free(node);
      }
      return;
    }
    Node *suc = successor(node);
    node->val = suc->val;
    suc->parent->left = suc->right;
    free(suc);
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
  Node *findNode(int key){
    Node* node = root;
    while(node != nullptr){
      if(node->val == key)
        return node;
      else if(key < node->val)
        node = node->left;
      else
        node = node->right;
    }

    return nullptr;
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
    std::cin >> cmd;
    if(cmd == "insert"){
      std::cin >> val;
      tree.insert(val);
    }
    else if(cmd == "find"){
      std::cin >> val;
      if(tree.find(val))
        std::cout << "yes\n";
      else
        std::cout << "no\n";
    }
    else if(cmd == "delete"){
      std::cin >> val;
      tree.erase(val);
    }
    else if(cmd == "print"){
      tree.print(tree.root, Inorder);
      std::cout << std::endl;
      tree.print(tree.root, Preorder);
      std::cout << std::endl;
    }
    n_cmd--;
  }
}
