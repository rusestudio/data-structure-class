#include <stdio.h>
#include <stdlib.h>

//struct node
typedef struct node {
    int key;
    struct node* next;
}node;

//struct hashtable
typedef struct hashtable {
    node** bucket;
    int size;
    int capacity;
} hashtable;

//1. create_hashtable
//will return table hashtable type
hashtable* create_hashtable(){

    //malloc hash table
    //hashtable type
    hashtable* table = (hashtable*)malloc(sizeof(hashtable));
    if (table == NULL){
        exit(1);
    }

    table->capacity = 100000;
    table->size = 0;

    table->bucket = (node**)calloc(table->capacity, sizeof(node*));
    if (table->bucket == NULL){
        free(table);
        exit(1);
    }
    return table;
}

//make index for table
//hash is actually index since cannot use same variable
//n%m + m %m for -ve incase
int hash(int key, int capacity){
    return (key%capacity +capacity)% capacity; //to get 0~m-1 index only no -ve index
}

//2. insert 
//only insert so no return type
void insert(hashtable* table, int key){
    //1. set index for insertion
    //which index? to insert
    int index = hash(key, table->capacity);

    //case 1: at current buket index have no previous node
    //make new node
    node* newnode = create_node(key);
    newnode->next = table->bucket[index];
    table->bucket[index] = newnode;
    table->size++;

    //case 2: at current buket index have previous node
    //make that prev as current cursor
    node* current = table->bucket[index];
    //if at this current != null add after the current
    while(current != NULL){
        if( current->key == key){ //check incase have duplicate key
            return;
        }
        current = current->next; //if no duplicate point insert at next
    }


    //case 3: while insert n/m>k so need to double m
    //let k = 0.75
    if(table->size/table->capacity > 0.75){
        resize_table(table);
    }
    
}

//3. create node
node* create_node(key){

    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        exit(1);
    }
    newnode->key = key;
    newnode->next = NULL;

    return newnode;
}

//4. resize_hashtable
void resize_hashtable(hashtable* table){

//we need to resize capacity & bucket only based on index
//need to double the m which is capacity 
//divide old and new 

int oldcapacity = table->capacity;
node** oldbucket = table->bucket;

//double the m
table->capacity = 2* oldcapacity;
table->bucket = (node**)calloc(table->capacity,(sizeof(node*));


}






int main(){

//insert n - size
int n;

//make table

hashtable* table = create_hashtable(); // implement this first- 1

scanf("%d", &n);
for(int i=0; i<n; i++){
    //input data
    int data;
    scanf("%d", &data);
    insert(table,data); //then implement this - 2
}


}
