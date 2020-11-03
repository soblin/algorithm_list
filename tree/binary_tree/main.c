#include <stdio.h>
#include <stdlib.h>

#define NIL -1
#define N 10000

typedef struct Node {
  int parent;
  int left;
  int right;
} Node;

Node Tree[N];
int Depth[N];
int Height[N];

void depth(int root, int root_depth){
  Depth[root] = root_depth;
  
  if(Tree[root].left != NIL){
    depth(Tree[root].left, root_depth + 1);
  }
  if(Tree[root].right != NIL){
    // traverse each child
    depth(Tree[root].right, root_depth + 1);
  }
}

int height(int root){
  int height1 = 0, height2 = 0;
  if(Tree[root].left != NIL){
    height1 = height(Tree[root].left) + 1;
  }
  if(Tree[root].right != NIL){
    height2 = height(Tree[root].right) + 1;
  }

  int ret = (height1 > height2)? height1 : height2;
  Height[root] = ret;
  return ret;
}

void print(int root){
  int sibling = -1;
  int degree = 0;
  int parent = Tree[root].parent;
  if(parent != NIL){
    if(root == Tree[parent].left){
      sibling = Tree[parent].right;
    }
    else{
      sibling = Tree[parent].left;
    }
  }
  degree += (Tree[root].left == NIL)? 0 : 1;
  degree += (Tree[root].right == NIL)? 0 : 1;
  
  printf("node %d: ", root);
  printf("parent = %d, ", Tree[root].parent);
  printf("sibling = %d, ", sibling);
  printf("degree = %d, ", degree);
  printf("depth = %d, ", Depth[root]);
  printf("height = %d, ", Height[root]);
  if(Tree[root].parent == NIL)
    printf("root\n");
  else if(Tree[root].left == NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}

int main(int argc, char **argv){
  int num;
  scanf("%d", &num);

  for(int i = 0; i < num; ++i){
    Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
    Depth[i] = 0;
    Height[i] = 0;
  }
    
  int id, left, right;
  for(int i = 0; i < num; ++i){
    scanf("%d %d %d", &id, &left, &right);
    Tree[id].left = left;
    Tree[id].right = right;
    if(left != NIL) Tree[left].parent = id;
    if(right != NIL) Tree[right].parent = id;
  }

  int root = -1;
  for(int i = 0; i < num; ++i) if (Tree[i].parent == NIL) root = i;
  
  depth(root, 0);
  int root_height = height(root);

  for(int i = 0; i < num; ++i)
    print(i);
}
