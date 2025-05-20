#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000000

int data[MAX_N]; // array to store valuse
int front =0; // index of front
int back =0; //index of where next element will be insert

void InitQ(int n){ //initialize q and fill data with n
  for (int i =1; i <=n; i++){
      data[back++] =i;//enqueue
  }
}

int Pop(){
    return data[front++]; //dequeue
}

int Front(){
    return data[front]; //1data at front, next to be dequeue
}


void PushBack(int x){ //insert x data at q
    data[back++] =x;
}

int main(){    //fifo queue

  int n;   // num of card
  scanf("%d", &n);   
 
  InitQ(n); // initialize q with val 1 to n
  
  while(back - front>1) { //loop till only 1 card left
         Pop();           //remove front card
         PushBack(Pop()); //move the next card to back
  }
  printf("%d", Front());


  return 0;
}
