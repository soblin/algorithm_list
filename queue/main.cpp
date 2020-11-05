#include <iostream>

struct Process {
  std::string name;
  int proc_time;
};

Process queue[1000];
int head = 0;
int tail = 0;

void enqueue(const std::string&name, const int proc_time){
  queue[tail].name = name;
  queue[tail].proc_time = proc_time;
  tail++;
}

bool empty(){
  return head == tail;
}

void dequeue(){
  head++;
}

int main(int argc, char **argv){
  int size, quantum;
  std::cin >> size >> quantum;

  head = 0;
  tail = 0;
  std::string name;
  int proc_time;
  int total_time = 0;
  for(int i = 0; i < size; ++i){
    std::cin >> name >> proc_time;
    enqueue(name, proc_time);
  }

  while(not empty()){
    name = queue[head].name;
    proc_time = queue[head].proc_time;
    if (proc_time > quantum){
      dequeue();
      total_time += quantum;
      enqueue(name, proc_time - quantum);
    }
    else {
      dequeue();
      total_time += proc_time;
      std::cout << name << ' ' << total_time << '\n';
    }
  }
}
