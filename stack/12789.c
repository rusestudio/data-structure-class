#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];

int main() {
    int n; //size
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]); //insert data n put in q
    }

    int nowserving = 1;      // now to serve number
    int top = -1;          // s 
    int front = 0;         // q

    while (front < n) { //front < size =5
        if (queue[front] == nowserving) { //1==1
            front++; //deque
            nowserving++; //increase next number to be serve
        } else if (top >= 0 && stack[top] == nowserving) { //top= serve
            top--; //pop top
            nowserving++; //increase next number to be serve
        } else {
            stack[++top] = queue[front++]; //put que to stack
        }
    }

    while (top >= 0) { // after q empty, now check stack to pop from there
        if (stack[top] == nowserving) { //top == next to serve
            top--; //pop
            nowserving++; // increase next to serve
        } else {
            break;
        }
    }

    if (nowserving == n+1) { //all serve
        printf("Nice");  //print nice
    } else {
        printf("Sad"); //else sad
    }

    return 0;
}

