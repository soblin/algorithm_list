#include <stdio.h>
#define N 50

#define UNVISITED (111)
#define VISITED (222)
#define FINISHED (333)

int n_node;
int mat[N][N];
int color[N];
int found_time[N];
int finished_time[N];
int cur_time;

void init(){
  cur_time = 1;
  for(int i = 0; i < N; ++i){
    color[i] = UNVISITED;
    found_time[i] = finished_time[i] = 0;
    for(int j = 0; j < N; ++j){
      mat[i][j] = 0;
    }
  }
}

void dfs(int u){
  if (color[u] == UNVISITED){
    color[u] = VISITED;
    found_time[u] = cur_time;
    cur_time++;
    for(int i = 0; i < n_node; ++i){
      if (mat[u][i] == 1) dfs(i);
    }
    // here, all out-node from u is visited
    color[u] = FINISHED;
    finished_time[u] = cur_time;
    cur_time++;
  }
}

int main(){
  init();
  scanf("%d", &n_node);
  for(int i = 0; i < n_node; ++i){
    int u, k, v;
    scanf("%d %d", &u, &k);
    u--;
    for(int j = 0; j < k; ++j){
      scanf("%d", &v);
      v--;
      mat[u][v] = 1;
    }
  }

  for(int i = 0; i < n_node; ++i){
    if (color[i] == UNVISITED) dfs(i);
  }

  for(int i = 0; i < n_node; ++i)
    printf("%d %d %d\n", i+1, found_time[i], finished_time[i]);
}
