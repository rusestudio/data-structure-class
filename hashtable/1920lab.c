#include <stdio.h>
#include <stdlib.h>

#define INITIALCAPACITY 100000
#define K 0.75

typedef struct Node{
    int key; //data
    struct Node* next; //link of next add like linked list
}Node;

typedef struct HashTable {
    Node** bucket; //continous bucket to point to node
    int capacity; //number of bucket
    int size; // number of unique key in node   
} HashTable;

HashTable* createHashTable(){
    //create one table with bucket, capacity , size in it
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL){ //doesnt matter if dont have 
        exit(1);        //but for safety to create memory better have 
    }

    //number or bucket(M)
    table->capacity = INITIALCAPACITY; //initialize 
    // number of key/data(N)
    table->size = 0;

    //for bucket make continously memory for bucket capacity based on node
    table->bucket = (Node**)calloc(table->capacity,sizeof(Node*));
    if (table->bucket == NULL){
        free(table);
        exit(1);
    }
    return table; //return the table
}

//to modular capacity based on key to choose which index data would be insert
//return will be from 0 ~ capacity
int Hash (int key, int capacity){
    return (key % capacity + capacity) % capacity;
    // incase the key have -ve value so +capacity to get +ve index
    // save version on n%m, incase n value is -ve
}


//void type no return
void Insert (HashTable* table, int key){

    //make index of the table
    int index = Hash(key, table->capacity);

    //create current index cursor
    Node* current = table->bucket[index];
    //table->bukets[index] == head_ptr
    //if key is not in the table
    while (current != NULL){
        if(current->key == key){
            return;
        }
        current = current->next;
    }

    //insert the key
    //create newnode
    Node* newNode = createNode(key);
    newNode->next = table->bucket[index];
    table->bucket[index] = newNode;
    table->size++;

    //if n/m > k double m 
    //then resize the hashtable
    if((double)table->size/table->capacity > K){
        resizeHashTable(table);
    }
    
}

Node* createNode(int key){
    //malloc node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        exit(1);
    }
    //check memory

    //initialize key 
    //initialize next -> NULL
    newNode->key = key;
    newNode->next = NULL;

    return newNode;
}

void resizeHashTable(HashTable* table){
    //initialize oldcapacity
    // init table bucke
    int oldCapacity = table->capacity;
    Node** oldBucket = table->bucket;

    // double bucket *2
    //make memory calloc again coz resize, so make new space
    table->capacity = 2* oldCapacity;
    table->bucket = (Node**)calloc(table->capacity, sizeof(Node*));
    //if current == old
    //make new hash value
    if(table->bucket == NULL){
        table->bucket = oldBucket;
        table->capacity = oldCapacity;
        return;
    }

    for (int i =0; i <oldCapacity; i++){
        Node* current = oldBucket[i]; //initialize current to oldbucket
        while (current != NULL){ //if no null
            Node* nodeToRehash = current; //move current to next
            current = current->next;
            //make newindex
            int newIndex = Hash(nodeToRehash->key,table->capacity);

            //reinsert newhash to next
            nodeToRehash->next = table->bucket[newIndex]; //head pointer to next newhash node
            table->bucket[newIndex]= nodeToRehash;
        }
    }
    free(oldBucket); //remove old bucket coz new we resize data to new hash
}

int main(){

    int n; //initialize size data
    int m; //initialize data to be search

    HashTable* table = createHashTable();//create table

    scanf("%d", &n); //input size data
    for (int i = 0; i < n; i++){ 
        int num;
        scanf("%d", &num); //input data
        Insert(table, num); //insert data in table
    }




}