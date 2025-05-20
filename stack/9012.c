#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push (char x){
    top++;
    stack[top] = x;
}

int pop(){
    if(top ==-1){
        return -1;
    }else {
      top--;
    }
}

int match (char* b){
    top =-1;

    for(int i=0; i< strlen(b); i++){
        if(b[i] == '('){
            push('(');
        } else if( b[i] == ')'){
            if(top ==-1){
                return 0;
            }
            pop();
        }
    }
   return top ==-1;
}


int main(){

    int T;
    scanf("%d", &T);


    char braket[MAX];

    for(int i =0; i <T; i++){
        scanf("%s", braket);

        if (match(braket)){
            printf("YES\n");
        }else {
            printf("NO\n");
        }

    }
    return 0; 
}

