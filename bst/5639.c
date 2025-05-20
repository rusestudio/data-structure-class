#include <stdio.h>
#include <stdlib.h>

//node 
struct bnode {
    int data;
   struct bnode* left;
   struct bnode* right;
};

//create new node 
struct bnode* createnode(int data){
    struct bnode* newnode = (struct bnode*)malloc(sizeof(struct));
    (*newnode).data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//insert data to node, return pointer type bnode
struct bnode* insert( struct bnode* root, int data){
    if(root == NULL){ //empty tree
        createnode(data);
        return root;
    }else if(data < root->data){ //if not empty <
        root->left = insert(root->left, data); //insert left
    }else{
        root->right = insert(root->right, data); //insert right
    }
    return root;
}

//tranversal
void tranverse1(struct bnode* root){
    if(root == NULL){
        return NULL;
    }else{
        tranverse1(root->left);
        tranverse1(root->right);
        printf("%d ", root->data);
    }

}


int main(){ 
struct bnode* root;// to store address of root pointer
root= NULL; //if know root can access to left n right

//ex insert dta
//insert(root,50);
//insert(root,30);
//insert(root,98);
//insert(root,52);
//insert(root,60);
//insert(root,24);
//insert(root,45);
//insert(root,5);
//insert(root,28);
//change this to loop

int data=0;
for(int i =0; i < 9; i++){
    scanf("%d", data);
    insert(root,data);
}

tranverse1(root);

}