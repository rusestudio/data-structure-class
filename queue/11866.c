

#include <stdio.h>

#define MAX_N 1000

int data[MAX_N]; // Array to store values
int front = 0;   // Index of front
int back = 0;    // Index where the next element will be inserted

void InitQ(int n) { // Initialize queue and push data with values 1 to n
    for (int i = 1; i <= n; i++) {
        data[back++] = i; // Push numbers from 1 to n
    }
}

void Pop(int k) {
    int index = (front + (k - 1));  // Calculate the position of the k-th person
    printf("%d", data[index]); // Print the person to be removed

    // Now we need to shift the remaining people
    for (int i = index; i < back - 1; i++) {
        data[i] = data[i + 1]; // Shift everyone after the removed person forward by 1
    }

    back--; // Decrease the size of the queue
    if (back - front > 0) printf(","); // Print a comma for separation (except for the last person)
}

int main() {  
    int n, k;
    scanf("%d %d", &n, &k); // Get the number of people (n) and the counting step (k)

    InitQ(n); // Initialize queue with values 1 to n, push

    while (back - front > 1) { // Loop until only 1 person remains
        Pop(k); // Pop the k-th person
    }

    // Finally, print the last remaining person
    printf("%d\n", data[front]);

    return 0;
}


