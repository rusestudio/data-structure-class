#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


char stack[MAX];
int top;

void push (char* x){
    top++;
    stack[top]= x;
}

int pop {
    if(top == -1){
        return -1;
    } else {
        top--;
    }
}

int match( char* x){
    for(int i =0; i < strlen(x); i++){
        if( x[i] == '[' || 
            x[i] == '(')
            push(x[i]);
        } else if (x[i] ==']'){
            pop();
        }
        
        

}







int main(){



    return 0;
}