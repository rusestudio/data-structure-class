#include <stdio.h>
#include <stdlib.h>

//make struct  node

struct Node {
    int ballon;
    int step;
    struct Node *next;
    struct Node *prev;
};

int main(){

    //insert ballon number
    int b;
    printf("insert ballon number:");
    scanf("%d", &b);  //5

    //initialize head and tail
    struct Node *head_ptr = NULL;
    struct Node *tail_ptr = NULL;

    int s;
    //insert step in list based on ballon num
    for(int i=1; i <=b; i++){  //will insert loop 5 time

    //insert step in ballon
    printf("insert step value:");
    scanf("%d", &s); // 3 2 1 -3 -1

    //make new node for step to get inserted
    struct Node *new_data = (struct Node*)malloc(sizeof(struct Node));
     (*new_data).ballon = i; //should be i not b coz in for loop ballon
     (*new_data).step = s;

     //now insert the new data
        if(head_ptr == NULL){
            //insert first data
            head_ptr= new_data;
            tail_ptr = new_data;
            new_data->next = new_data;
            new_data->prev = new_data;
        }else{
            //insert data after head <-> new data, always start at heads
            new_data->next = head_ptr;
            new_data->prev = tail_ptr;
            tail_ptr->next = new_data; //tail only have next coz last
            head_ptr->prev = new_data; //head only have prev coz next is 1data and its it circular so gonna point prev too
            tail_ptr= new_data;
        }
        //printf("%d\n", (*new_data).step); //check if insert is well
    }

     //now to pop the first ballon
     //make new node for current ballon data that to be pop
     struct Node *current = head_ptr; //put current in head

     for(int i = 0; i < b; i++){ //will loop 5 times  for 5 ballon
        //print current ballon number
        printf("%d ,", (*current).ballon); //1 ,2 3, 4, 5
        //since current pointing at head = 1

        //check if current i ballon -1 which last then break
        if( i == b-1){
            free(current); //since class free the deleted
            break;
        }

        //to get the step value
        //save the move val in var first
        int move = (*current).step; //int type

        //to move the current make new pointer
        struct Node *c_next = current->next;
        struct Node *c_prev = current->prev;

        //remove the current node , if first i=1
        if( current->next == current){
            //if current n next is same mean data is last
            free(current);
            head_ptr = NULL; // so make head null
            break;
        }else{
            //now remove
            c_next->prev = c_prev; //current next that pointing at prev now is prev
            c_prev->next = c_next; // current prev that pointing at next is now next
            //because next and prev is removed

            //if current == head , then move the head to  current next because we dont want
            //head to be remove yet
            if(current == head_ptr){
                head_ptr = c_next;
            }
        }
        free(current);// current that got removed above which is the 1 ballon
        
     //find next ballon to be pop based on move /steps
     if(move > 0){
        current = c_next; //put the c next into current
            for(int j =1; j <move; j++){ //to loop amount of move ex: 3 so loop move 3 time to get to the next ballon to be pop
                current = current->next; // make next = current
            }
     }else{
        current= c_prev; //if the move is -ve val. like -1 so move loop backward
        for (int j=1; j < -move; j++){ //to loop backward based on move
            current= current->prev; // make the next prev is current
        }
     }

    }

    return 0;
}