#include <stdio.h>
#include <stdlib.h>

//node struct for doubly linked list
struct Node {
    int number;  //ballon number (identifier)
    int value;   //paper value insdide balon (movement steps)
    struct Node *next; //pointer to next node
    struct Node *prev; //pointer to prev node
};

int main(){
    int N;
    scanf("%d", &N); //read number of ballon

    //initialize head n tail pointer to null
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int value;
    for(int i =1 ;i <= N; i++){
        scanf("%d", &value); // read the value/movement steps inside ballon

        //create new node and mak memory for it
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        if(new_node==NULL){
            printf("memory alloction failed\n");
            exit(1);
        }

        //here data type is int
        //new node number assign to ballon number i/N coz in for loop
        new_node->number =i;
        //new node value assign to value/movement steps
        new_node->value= value;  

        // if it the first node, initalize first node of circular links
        if(head==NULL){ //if data only one
            head= new_node; //declare all point at new node
            tail= new_node;
            new_node->next = new_node; //point to itself coz circular
            new_node->prev = new_node;
        } else {
            new_node->prev = tail;//if already have data
            new_node->next= head;// insert the ada at the end of list/ next
            tail->next = new_node;// changing the tail at next to newnode
            head->prev = new_node;// change hea head to the prev newnode
            tail = new_node; //update tail pointer

        }

    }

    //pop the ballons
    struct Node *current = head; //start from first ballon/head

    for (int i =0; i < N; i++){
        printf("%d", current-> number); //print curent ballon number

        if (i ==N -1){ //if last ballon, break
            break;
        }

        //store move value and get next node reference before remove
        int move_steps = current->value; // put value data as step
        //struct Node *next_node = current->next;//assign nextnode to current next
        //struct Node *prev_node = current->prev;//assign nextnode to current prev

        //remove current node from list
        if(current->next == current){   
            head =NULL; //list is empty
        } else{
            //xt_node->prev = prev_node; //change nextnode to prev
            //ev_node->next = next_node; //change prevnode to next
            current->next->prev = current->next;
            current->prev->next = current->prev;

            //update head if removing head
            if(current== head){ //if happen need to remove head
                head = current->next; //move the head to next node
            }
        }

        //free the removed node
        struct Node *to_delete = current;

        //Find the next ballon to be pop
        if(move_steps >0){
            current = to_delete->next;
            //move forward (move_steps -1)times
            for(int j =1; i<move_steps; j++){
                current= current ->next;
            }
        }else {
            current = to_delete->prev;
            //move backward(absolute value of move_steps)-1)times
            for(int j=1; j < -move_steps; j++){
                current = current->prev;
            }
        }

        //free the node
        free(to_delete);

    }

    //free any remains nodes
    if(head != NULL){
        free(head);
    }

    return 0;
}