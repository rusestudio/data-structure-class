#include <stdio.h>
#include <stdlib.h>

//declare node
struct Node{
    int number;
    int value;
    struct Node* next;
    struct Node* prev;
};


//insert 
struct Node* insert(struct Node* head, struct Node* tail, int data, int value){
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));

    newnode->number= data;
    newnode->value = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    } else{
       newnode->prev= tail;
       newnode->next = head;
       head->prev = newnode;
       tail->next = newnode;
       head = newnode;
    }
}

//delete

int main(){

    int num;
    scanf("%d", &num);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    int val;
    for(int i=0; i < num; i++){
        scanf("%d", &val);
        insert(head, tail, num, val);
    }

    //to delete ballon based on value
    struct Node* current = head;
    struct Node* todelete = current;


while( num < current->number){
    printf("%d", current->number); //print cyrrent ballon

    //change link delete middle
    if( current->next == current){
        head = NULL;// head is empty
    }else {
        current->next->prev = current->next;
        current->prev->next = current->prev;

        if(current==head){
            head = current->next; //incase current is head. we dont want to delete head
        }
    }

    //move based on value
    int movestep= current->value; 

    if (movestep > 0){
        current = todelete->next;
        for(int i =1; i < movestep; i++){
            current = current->next;
        }
    }else{
        current= todelete->prev;
        for(int i=1; i< movestep; i++){
            current = current->prev;
        }
    }
}
    free(todelete);

    return 0;
}