#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxQueueSize 256
#define E_OK 1

int enqueue(int x);
int dequeue();
int shuffle();

int queue[maxQueueSize];
int count = 0;

int enqueue(int x){
  if(count == maxQueueSize){
    fprintf(stderr, "ERROR: Max queue size has been exceeded");
    return -1;
  }
  queue[count] = x;
  count++;
  return E_OK;
}

int dequeue(){
  if(count == 0){
    fprintf(stderr,"ERROR: Min queue size has been reached");
    return -1;
  }
  int retVal;
  retVal = queue[0];
  shuffle();
  count--;
  return retVal;
}

int shuffle(){
  for(int i = 1; i < count; i++){
    queue[i-1]=queue[i];
  }
  return E_OK;
}

int front(){
  return queue[0];
}

int main(int argc, char* argv[]){
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(5);
  
  while(count > 0){
    printf("%d \n", dequeue());
  }
  return 0;
}