#include <iostream>

// int Node[1000];
int Left[1000];
int Right[1000];
int Parent[1000];
int Depth[1000];
int Height[1000];
int Sibling[1000];
int Degree[1000];

int setHeight(int root){
  int height_l = 0, height_r = 0;
  if(Left[root] != -1)
    height_l = setHeight(Left[root]) + 1;
  if(Right[root] != -1)
    height_r = setHeight(Right[root]) + 1;

  int height = (height_l > height_r)? height_l : height_r;
  Height[root] = height;

  return height;
}

int main(int argc, char **argv){
  int num;
  std::cin >> num;
  Parent[0] = -1;
  Depth[0] = 0;
  Sibling[0] = -1;
  
  for(int i = 0; i < num; ++i){
    int node, left, right;
    std::cin >> node >> left >> right;
    Left[node] = left;
    if (left != -1){
      Parent[left] = node;
      Depth[left] = Depth[node] + 1;
      Sibling[left] = right;
      Degree[node] = 1;
    }
    Right[node] = right;
    if (right != -1){
      Parent[right] = node;
      Depth[right] = Depth[node] + 1;
      Sibling[right] = left;
      Degree[node] = 2;
    }
  }

  int root_height = setHeight(0);
  for(int i = 0; i < num; ++i){
    std::cout << "node " << i << ": ";
    std::cout << "parent = " << Parent[i] << ", ";
    std::cout << "sibling = " << Sibling[i] << ", ";
    std::cout << "degree = " << Degree[i] << ", ";
    std::cout << "depth = " << Depth[i] << ", ";
    std::cout << "height = " << Height[i] << ", ";
    std::string type;
    if (Parent[i] == -1)
      type = "root";
    else if(Left[i] == -1)
      type = "leaf";
    else
      type = "internal node";

    std::cout << type << "\n";
  }
}
