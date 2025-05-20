 #include <stdio.h>
#include <stdlib.h>

#define MaxSizeStack 1000000

int mystack[MaxSizeStack];
int top = -1; //empty stack , top is index

void Push(int value) {
    if(top >= MaxSizeStack-1){
        return "stack is full";
    } else{
        top++;
        mystack[top] = value;
    }
    
}

int Pop() {
    if(top == -1){
        return "stack is empty";
    } else{
        int value;
        value = mystack[top];
        top--;
    }
}

int Size() {
    return top + 1;
}
                                                                                                  
int IsEmpty() {
    if(top == -1){
        return "true";
    }else{
        return "false";
    }
}

int Top() {
    if (top == -1) {
        return "stack is empty";
    }
    return mystack[top];
}

int main() {

    int n; //number of command
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        int command;
        scanf("%d", &command);

        switch (command) {
            case 1: {
                int x;
                scanf("push:%d", &x);
                Push(x);
                break;
            }
            case 2: {
                printf("pop:%d\n", Pop(&mystack));
                break;
              }
              case 3: {
                printf("size:%d\n", Size(&mystack));
                break;
              }
              case 4: {
                printf("isempty:%d\n", IsEmpty(&mystack));
                break;
              }
              case 5: {
                printf("top:%d\n", Top(&mystack));
                break;
              }
        }
    }

    return 0;
}
