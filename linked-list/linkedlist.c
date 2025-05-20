// to make linked list
//1. declare a struct first

define MAX =10;

typedef struct Node //now struct type is call Node
{
    int data;  //data val
    struct Node *link;   //pointer address
} Node;

Node *head_ptr;  //make head pointer, data type is struct node* = address
Node * tail_ptr; //make tail pointer

head_ptr = NULL; // 초기화 
tail_ptr = NULL; // no * so it is address

//2. set value inside list
(*head_ptr).data =4; //or
head_ptr->data =4; 
//when use * or -> it become data val not address

//to print
printf("%d\n", (*head_ptr).data);
printf("%d\n", head_ptr->data);

//3. find length of linked list or called traversing
size_t list_length( Node *head_ptr){

    Node *cursor; //the point to be move to count, address
    size_t length =0;

    // for( 초기화, loop until cursor reach before null, put link val in cursor)
    for(cursor = head_ptr; cursor !=NULL; cursor = cursor->link)
        length++; //increase length , mean increse number of data everytime loop

    return answer;
    
}

//4. insert data at head(insert at front)
void insert_head(struct Node* head_ptr, int newdata)
{
    struct Node *insert_ptr;// declare new pointer to get inserted, more like a temp pointer
    insert_ptr = (struct Node*)malloc(sizeof(struct Node))// make memory for new data
    insert_ptr->data = 8; //insert new data val at pointer
    insert_ptr->link = head_ptr //change address  to head coz address of next val is head
    head_ptr = insert_ptr // put all back into head_ptr
    //so now temp insert_ptr will disappear
}

//5. insert data not at head (at back or, middle)
void insert_anywhere(struct Node* previous_ptr, int newdata)
{
    struct Node *insert_ptr // declare temp to insert
    insert_ptr = (struct Node*)malloc(sizeof(struct Node))//make memory
    insert_ptr->data = 9; //insert new data
    insert_ptr->link = previous_ptr->link; //change address to previous ptr coz now its pointing to prev data's 
    previous_ptr = insert_ptr //put all back into previous
}

//6. search data in linked list, return data's address
struct Node* search_data(struct Node* head_ptr, int target)
{
    struct Node *cursor; //declare pointer to find data
    for( cursor = head_ptr; cursor!=NULL; cursor= cursor->link)
        if(target== cursor->data) //if target == data, both in int type can compare
            return cursor;        //return the data's address
    return NULL:                   //else return NULL

}

//7. search nth position in linked list, return address
struct Node* search_n(struct Node* head_ptr, size_t n_position)
{
    struct Node* cursor; //declare pointer to find nth 
    size_t i; //size is i, first node in list has position=0
    
    cursor= head_ptr;
    for(i =0; (i< n_position) && (cursor != NULL); ++i )
        cursor = cursor->link; //put found n_position address in cursor
    return cursor; //return address of n_position
}

//8. remove node at head
void list_head_remove(struct Node* head_ptr)
{
    struct Node *remove_ptr; //declare remove pointer
    remove_ptr = head_ptr; //head n remove are pointing at same node/data
    head_ptr = head_ptr->link; //change address to point at next data's address
    //cannot work if head_ptr->link is null.
    //so check - if(head_ptr==NULL) return NULL;
    delete remove_ptr; //delete the data that remove are pointing
    //since head now pointing at next data remove_ptr is head and it can be delete

}

//9. remove node at anywhere else
void lis_remove(struct Node* previous_ptr)   
{
    //ex data 8.9[ad 3.5] 3.5[ad 6.2] 6.2[null]
    struct Node *remove_ptr; //declare remove ptr
    remove_ptr = previous_ptr->link; //point to address want to  be delete[add 6.2]
    previous_ptr->link = remove_ptr->link; // point remove to that address. 
    //pointer to be remove = remove link
    delete remove_ptr; //then delete address
}

int main(int){

    int data=0;
    int n;

    printf("first data you want to insert in list: %d", data);
    scanf("%d", &data);
    insert_head(data);

    printf("next data you want to insert in list: %d", data);
    scanf("%d", &data);
    insert_anywhere(data);

    printf("data to be search: %d", data);
    scanf("%d", &data);
    search_data(data);

    printf("location to be search: %d", n);
    scanf("%d", &n);
    search_n(n);

    printf("length of data is:");
    size_t()

    return 0;
}

