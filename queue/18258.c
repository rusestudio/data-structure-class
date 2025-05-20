#include <stdio.h>
#include <stdlib.h>

#define kMaxqsize 2000000 //max q size

int data[kMaxqsize]; // array to store valuse
int front =0; // index of front
int back =0; //index of where next element will be insert
int size =0; // num of element in q

void InitQ(){ //initialize q
  front =0;
  back=0;
  size=0;
}

void Push(int x){
  data[back++] =x; //insert x at back index
  size++; //increase size
}

int Pop(){
  if(size==0){ //array is empty
    return -1;
  }
    size--; //decrease size
    return data[front++]; //return front element and move front foward
}

int Size(){ //return current q size
  return size;
}

int Empty(){
  if(size==0){
    return 1;  //size 0 return 1 else 0
  }else {
    return 0;
  }
}

int Front(){
  if (size ==0){ //return front element w/o remove it
    return -1;
  } else{
    return data[front];
  }
}

int Back(){ //return last element inserted
  if(size==0){
    return -1;
  } else {
    return data[back-1];
  }
}

int main(){

  int n;
  scanf("%d", &n);

  InitQ(); // initialize q

  char command[] ="";
  
  for(int i =0; i<n; i++){ //loop as much n
  
    scanf("%s", command);

    if(command == 'push'){ //if push
      int x;
      scanf("%d", &x);  //enter element to inser in q
      Push(x);  // call push
    } else if (command == 'pop'){
      printf("%d", Pop());
    } else if (command == 'size'){
      printf("%d", Size());
    } else if (command[0] == 'e'){
      printf("%d", Empty());
    } else if (command[0] == 'f'){
      printf("%d", Front());
    } else if (command == 'back'){
      printf("%d", Back());
    } else {
      printf("wrong command");
    }




  }


  return 0;
}