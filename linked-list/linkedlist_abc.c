#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Fixed define statement

typedef struct Node // now struct type is called Node
{
    int data;  // data value
    struct Node *link;   // pointer address
} Node;

Node *head_ptr;  // make head pointer, data type is struct node* = address
Node *tail_ptr; // make tail pointer

head_ptr = NULL; // 초기화 
tail_ptr = NULL; // no * so it is address

// 3. find length of linked list or called traversing
int list_length(Node *head_ptr){  
    Node *cursor; // the point to be moved to count, address
    int length = 0;

    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link)
        length++; // increase length, means increase number of data every time loop

    return length;
}

// 4. insert data at head (insert at front)
void insert_head(Node **head_ptr, int newdata) 
{
    Node *insert_ptr; // declare new pointer to get inserted, more like a temp pointer
    insert_ptr = (Node*)malloc(sizeof(Node)); // make memory for new data
    if (!insert_ptr) return; // Check if malloc failed
    insert_ptr->data = newdata; // insert new data val at pointer
    insert_ptr->link = *head_ptr; // change address to head because now it's pointing to head
    *head_ptr = insert_ptr; // put all back into head_ptr
}

// 5. insert data not at head (at back or, middle)
void insert_anywhere(Node *previous_ptr, int newdata)
{
    if (previous_ptr == NULL) return; // Check if previous_ptr is NULL

    Node *insert_ptr; // declare temp to insert

    insert_ptr = (Node*)malloc(sizeof(Node)); // make memory
    if (!insert_ptr) return; // Check if malloc failed

    insert_ptr->data = newdata; // insert new data
    insert_ptr->link = previous_ptr->link; // change address to previous ptr because now it's pointing to prev
    previous_ptr->link = insert_ptr; // put all back into previous
}

// 6. search data in linked list, return data's address
Node* search_data(Node *head_ptr, int target)
{
    Node *cursor; // declare pointer to find data
    for(cursor = head_ptr; cursor != NULL; cursor= cursor->link)
        if(target == cursor->data) // if target == data, both in int type can compare
            return cursor;        // return the data's address
    return NULL;                   // else return NULL
}

// 7. search nth position in linked list, return address
Node* search_n(Node *head_ptr, int n_position)
{
    Node* cursor; // declare pointer to find nth 
    cursor = head_ptr;
    for(int i = 0; (i < n_position) && (cursor != NULL); ++i )
        cursor = cursor->link; // put found n_position address in cursor
    return cursor; // return address of n_position
}

// 8. remove node at head
void list_head_remove(Node **head_ptr)
{
    if (*head_ptr == NULL) return; // Check if list is empty

    Node *remove_ptr; // declare remove pointer
    remove_ptr = *head_ptr; // head and remove_ptr are pointing at the same node/data
    *head_ptr = (*head_ptr)->link; // move head pointer to the next node
    free(remove_ptr); // delete the node at the head
}

// 9. remove node at anywhere else
void list_remove(Node *previous_ptr)   
{
    if (previous_ptr == NULL || previous_ptr->link == NULL) return; // Check for invalid cases

    Node *remove_ptr; // declare remove pointer
    remove_ptr = previous_ptr->link; // point to the node to be deleted
    previous_ptr->link = remove_ptr->link; // update previous pointer to skip deleted node
    free(remove_ptr); // delete the node
}

int main() {
    int data = 0;  // Variable to store user input data
    int n;  // Variable to store position input

    // Prompt user to enter first data
    printf("first data you want to insert in list: ");
    scanf("%d", &data);  
    insert_head(&head_ptr, data);  

    // Prompt user to enter next data
    printf("next data you want to insert in list: ");
    scanf("%d", &data);  
    insert_anywhere(head_ptr, data);  

    // Prompt user to search for a data value
    printf("data to be searched: ");
    scanf("%d", &data);  
    Node *found = search_data(head_ptr, data);  

    if (found)
        printf("Data %d found at address %p\n", data, found); 
    else
        printf("Data not found\n");

    // Prompt user to search for a specific position in the list
    printf("location to be searched: ");
    scanf("%d", &n);  
    Node *nth_node = search_n(head_ptr, n);  

    if (nth_node)
        printf("Data at position %d: %d\n", n, nth_node->data);
    else
        printf("Invalid position\n");

    // Print the length of the linked list
    printf("length of data is: %d\n", list_length(head_ptr));

    // Prompt user to remove head node
    char choice;
    printf("Do you want to remove the head node? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        list_head_remove(&head_ptr);
        printf("Head node removed.\n");
    }

    // Prompt user to remove a specific node
    printf("Enter data of node you want to remove: ");
    scanf("%d", &data);
    Node *prev_node = NULL;
    Node *cursor = head_ptr;

    // Find the previous node of the target node
    while (cursor != NULL && cursor->link != NULL) {
        if (cursor->link->data == data) {
            prev_node = cursor;
            break;
        }
        cursor = cursor->link;
    }

    if (prev_node) {
        list_remove(prev_node);
        printf("Node with data %d removed.\n", data);
    } else {
        printf("Node with data %d not found or cannot be removed.\n", data);
    }

    return 0;  
}
