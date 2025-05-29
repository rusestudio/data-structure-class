#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {  //array
    int* arr;  //array add  arr[index] = *(arr+index)
    int capacity; // N
    int size; 
} MinHeap;

void SwapElements(int* a, int* b) {
    int temp = *a;  //if data is smaller swap the data use temp
    *a = *b;
    *b = temp;
}

MinHeap* CreateMinHeap(int capacity) { //create min heap
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap)); //make memory
    if (heap == NULL) {
        exit(1); //if no memory in os exit
    }
    //heap->arr = address of data in array
    heap->arr = (int*)calloc(capacity + 1, sizeof(int)); // capacity+1 = 1~N, coz heap start from 1 
    if (heap->arr == NULL) {
        free(heap);
        exit(1); //if no calloc exit
    }
    heap->capacity = capacity; //initialize capacity
    heap->size = 0;           //init size
    return heap;               //return heap
}

void MinHeapifyDown(MinHeap* heap, int idx) {
    int smallest = idx;
    int left_child_idx = 2 * idx;
    int right_child_idx = 2 * idx + 1;

    if (left_child_idx <= heap->size && heap->arr[left_child_idx] < heap->arr[smallest]) {
        smallest = left_child_idx;
    }

    if (right_child_idx <= heap->size && heap->arr[right_child_idx] < heap->arr[smallest]) {
        smallest = right_child_idx;
    }

    if (smallest != idx) {
        SwapElements(&heap->arr[idx], &heap->arr[smallest]);
        MinHeapifyDown(heap, smallest);
    }
}

//to find the data place that root<=data
void MinHeapifyUp(MinHeap* heap, int idx) {  
    //while not true loop- keep going up to compare if it small go up
    while (idx > 1 && heap->arr[idx] < heap->arr[idx / 2]) {
        SwapElements(&heap->arr[idx], &heap->arr[idx / 2]);
        idx = idx / 2; 
        //index/2 will make data go up to compare with root. loop till root is <=data
    }
}

//insert to (table, data)
void MinHeapInsert(MinHeap* heap, int k) {
    if (heap->size == heap->capacity) { //if size== capacity which is full but can never
        return;
    }

    heap->size++; //size=1 
    heap->arr[heap->size] = k; // add value k into the heap array at last leaf

    MinHeapifyUp(heap, heap->size); // to compare size to see if the data is in right place or not
}

int MinHeapExtractMin(MinHeap* heap) {
    if (heap->size < 1) { 
        exit(1);
    }

    int root = heap->arr[1]; 

    if (heap->size == 1) {
        heap->size--;
        return root;
    }

    heap->arr[1] = heap->arr[heap->size];
    heap->size--; 

    if (heap->size > 0) { 
        MinHeapifyDown(heap, 1);
    }
    
    return root;
}

void FreeMinHeap(MinHeap* heap) {
    if (heap == NULL) {
        return;
    }
    if (heap->arr != NULL) {
        free(heap->arr);
    }
    free(heap);
}

int main() {
    int N; 
    scanf("%d", &N); //input number on n size

    MinHeap* pq = CreateMinHeap(N); //create minheap based on n

    for (int i = 0; i < N; i++) {
        int card_size;
        scanf("%d", &card_size);  //input data(card)
        MinHeapInsert(pq, card_size);
    }

    int total_comparisons = 0;

    while (pq->size > 1) {
        int first_smallest = MinHeapExtractMin(pq);
        int second_smallest = MinHeapExtractMin(pq);

        int current_sum = first_smallest + second_smallest;
        total_comparisons += current_sum;

        MinHeapInsert(pq, current_sum);
    }

    printf("%d\n", total_comparisons);

    FreeMinHeap(pq);

    return 0;
}