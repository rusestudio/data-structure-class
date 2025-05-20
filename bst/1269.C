#include <stdio.h>
#include <stdlib.h>

struct BSTNode {

    int key;
    struct BSTNode* left;
    struct BSTNode* right;
};

//create node
BSTNode* createNode(int data){

    //make memory for new node
    BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
    if (new_node == NULL){ //check for failes
        printf("-1");
    }else{
        (*new_node).key = data; //initialize data to key
        new_node->left = NULL; //initualize left to null
        new_node->right= NULL; //initialize right to null
        return new_node;  //then return newnode mean newnode is created
    }
}

//insert data
BSTNode* insert_data(BSTNode* root, int data){
        //check if root is null or not
        if(root == NULL){
            return createNode(data);
        }

        if(data < root->key){
            return insert_data(root->left, data);
        } else if( data > root->key){
            return insert_data(root->right, data);
        }

        //return root;

}

//search data
BSTNode* search_data(BSTNode* root, int target){
        //check if root is null or not
        if(root== NULL){
            return NULL;
        }
        //if found return the key
        if(target == root->key){
            return root;
        }
        //if not found, search left and right
        if( target < root->key){
            return search_data(root->left, target);
        } else if (target > root->key){
            return search_data(root->right, target);
        }

}

