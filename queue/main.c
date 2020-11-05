#include <stdio.h>
#include <string.h>

typedef struct Process {
  char name[16];
  int time;
} Process;

Process queue[1000];
int head = 0;
int tail = 0;
int proc_time = 0;

void enqueue(char *name, int time){
  strcpy(queue[tail].name, name);
  queue[tail].time = time;
  tail++;
}

void dequeue(){
  head++;
}

int empty(){
  return (head == tail)? 1 : 0;
}

int main(int argc, char **argv){
  char buf[100];
  int tm;
  int size;
  int quantum;
  scanf("%d %d", &size, &quantum);

  head = 0;
  tail = 0;
  for(int i = 0; i < size; ++i){
    scanf("%s %d", buf, &tm);
    enqueue(buf, tm);
  }

  while(!empty()){
    int cur_proc_time = queue[head].time;
    strcpy(buf, queue[head].name);
    if(cur_proc_time <= quantum){
      proc_time += cur_proc_time;
      dequeue();
      // print the result
      printf("%s %d\n", buf, proc_time);
    }
    else{
      cur_proc_time -= quantum;
      proc_time += quantum;
      dequeue();
      enqueue(buf, cur_proc_time);
    }
  }
  
  return 0;
}
