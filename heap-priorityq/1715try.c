#include <stdio.h>
#include <stdlib.h>

//minheap struct
typedef struct minheap {
    int* arr;
    int capacity; //length of array
    int size; //number of data in array
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
    //add data at the end/last of the leaf which mean heap의 size만큼 coz its array which mean end of array
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
        //make index divide 2 which mean swapped data become parent. the more up the smaller index

    }
}

//swap data's address use temp
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

//return int type need for addition
int minheapGet_n_RemoveSmallest(minheap* heap){
    //get smallest at root which is 1 index
    int root = heap->arr[1]; 

    if(heap->size == 1){
        heap->size--;
        return root; //return root when the data left in array is 1
    }

    //swap the last left to root after root is deleted(removing)
    heap->arr[1] = heap->arr[heap->size];
    heap->size--; //size-- coz deleted 

    if(heap->size > 0){ //if size > 0
        minheapifydown(heap, 1); //check if the data is match the heap properties or not. start from root index 1
    }

    return root; //return root(the data that we get from last child now at root)
}

void minheapifydown(minheap* heap, int index){
    //set the index for root(smallest), right and left child
    int smallest_root = index; // ex: 1
    int left_child_idx = index*2; // 2
    int right_child_idx = index*2 +1; //3

    //then check if data are in right place or not. means data is the smallest or not
    //left/right <=heap->size - to check if index is valid
    //compare left first
    if(left_child_idx <= heap->size && heap->arr[left_child_idx] < heap->arr[smallest_root]){
        smallest_root = left_child_idx;
        //if left < root. then go down root = left. 
        //means left root can be candidate to be new root
    }

    if(right_child_idx <= heap->size && heap->arr[right_child_idx] < heap->arr[smallest_root]){
        smallest_root = right_child_idx;
        //if right < root. then go down root = right.
        //means right root can be candidate to be new root
    }

    //only if smallest_root != 1 which is index then do swap. until we reach the top.
    //if smallest_root == 1 means done. 
    if(smallest_root != index){
        //swap the data with the candidate
        swap(&heap->arr[index], &heap->arr[smallest_root]);
        minheapifydown(heap,smallest_root); //recursion call, to keep going down after swap use current smallest.

    }
}

void FreeMinHeap(minheap* heap){
    if (heap == NULL){
        return;
    }
    if(heap->arr != NULL){
        free(heap->arr);
    }
    free(heap);
}

int main(){

    int n;
    scanf("%d", &n); // nsize

    //make heap table pq based on size(n)
    minheap* pq = createMinheap(n);

    for(int i=0; i<n; i++){
        int card_size;
        scanf("%d", &card_size); //data
        minheapInsert(pq, card_size); //insert to table
    }

    int total_comparison = 0;

    while (pq->size >1){   //ex data 10,20,40 //40,30
        int first_smallest = minheapGet_n_RemoveSmallest(pq); //10 //30
        int second_smallest = minheapGet_n_RemoveSmallest(pq); //20 //40

        int current_sum = first_smallest + second_smallest; //10+20 = 30 //30+40 = 70
        total_comparison = total_comparison+ current_sum; //0+30 =30 //30+70 = 100

        minheapInsert(pq, current_sum); //insert 30, then repeat with 40  // insert 70
    }

    printf("%d\n", total_comparison); //print 100;

    FreeMinHeap(pq);

    return 0;


}