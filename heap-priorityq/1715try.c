#include <stdio.h>
#include <stdlib.h>

//minheap struct
typedef struct minheap {
    int* arr;
    int capacity;
    int size;
} minheap;

minheap* createMinheap( int size){
    //make table 
    minheap* heap = (minheap*)malloc(sizeof(minheap));
    //check if have memory
    if(heap == NULL){
        exit(1);
    }

    //initialize addresss of arr or arr[index], coz index gonna start with 1 so +1
    heap->arr = (int*)calloc(capacity + 1, sizeof(int));
    if(heap->arr == NULL){
        exit(1);
    }
    //initialize capacity
    heap->capacity = capacity;
    //initialize size index
    heap->size = 0;

    return heap;
}

void minheapInsert(minheap* heap, int data){
    //when add size increase
    heap->size++; 
    //add data at the end of the leaf
    heap->arr[heap->size] = data;

    //now need to find data place that satisty the heap cond which is root<=data
    minheapifyUp(heap, heap->size); // size==index
}

void minheapifyUp(minheap* heap, int index){
    //while data is smaller than root keep going up and swap the place
    //index >1 && data < data/2
    //index > 1 means its the first index the so cannot be more than that. if not keep going up 
    //means data is the smallest in the heap arr
    //ex: index > 1 && 6 < 6/2 = 3 , 3 less 6 so swap
    while(index > 1 && heap->arr[index] < heap->arr[index/2] ){ // heap->arr[index] is to swap data
        //swap the place
        swap(&heap->arr[index], &heap->arr[index/2]); //swap data is the condition not satisfy
        index = index/2; // after swap data, now swap index coz going up.like swap but actually index/2
        //index/2 is the root index. and index is the data that we want to compare


    }
}

//swap data's address use temp
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

}


int main(){

    int n;
    scanf("%d", &n); // nsize

    //make heap table pq based on size(n)
    minheap* pq = createMinheap(n);

    for(int i=0; i<n; i++){
        int card_size;
        scanf("%d", &card_size);
        minheapInsert(pq, card_size); //insert to table
    }


}