#include <stdio.h>
#include <stdlib.h>

//create struct node
struct bstnode {

    int data;
    struct bstnode* left;
    struct bstnode* right;
};

//create node
struct bstnode* create_node(int data){

    struct bstnode* new_node =(struct bstnode*)malloc(sizeof(struct bstnode));
    if(new_node == NULL){
        return NULL;
    }
     new_node->data= data;
     new_node->left = NULL;
     new_node->right = NULL;
return new_node;
}


//insert node 
struct bstnode* insert(struct bstnode* root, int data){
    int counter;

    if (root == NULL){
        return create_node(data);
    }

    if(data < root->data){
        root->left = insert(root->left, data);
    } else {
        root->right= insert(root->right, data);
    }
    return root;

}

//search n count
int search (struct bstnode* root, int data){
    if(root == NULL){
        return -1;
    }

    if (data == root->data){
        return 1;
    } else if (data < root->data){
       return search(root->left, data);
    } else{
       return search(root->right, data);
    }
}

//tranversal root-left-right
//void tranverse1(struct bnode* root){
  //  if(root!= NULL){
    // printf("%d ", root->data); //visit the root
     //tranverse1(root->left);
     //tranverse1(root->right);
    //}
 //}

void transverse_check(struct bstnode* rootA, struct bstnode* rootB, int* counter){
    if(rootA == NULL){
        return;
    }else{
        transverse_check(rootA->left, rootB, counter);
        if(search(rootB, rootA->data) == 1){
         (*counter)++;
         }
         transverse_check(rootA->right, rootB, counter);
        }
    
}


//main

int main(){

    //input size A
    int nA;
    printf("enter size a:");
    scanf("%d", &nA);

    //input size B
    int nB;
    printf("enter size b:");
    scanf("%d", &nB);

   struct bstnode* seta = NULL;
   struct bstnode* setb = NULL;

   //insert all A into setA
   int data;
    for(int i =0; i <nA; i++){
        printf("enter data a:");
        scanf("%d", &data);
        seta = insert(seta, data);
        
    }

    //insert set B then search each time after insert
    // if have same in set a counter++
    int datab;
    for(int i =0; i <nB; i++){
        printf("enter data b:");
        scanf("%d", &datab);
        setb = insert(setb, datab); //insert data in setb
    }

    int counter=0;

    //loop through each element in seta
    //if(seta->left != NULL && seta->right != NULL){
      //  if(search(seta, data) ==1){
        //    counter = counter+1;
          // };
    //}

    //loop through each element in setb
    //if(setb->left != NULL && setb->right != NULL){
      //  if(search(setb, datab) ==1){
        //    counter = counter+1;
          // };
    //}

    int r1=0;
    if(transverse(search(seta, data)) ==1){
        r1 = counter+1;
    }

    int r2=0;
    if(transverse(search (setb, datab)) ==1){
        r2 = counter+1;
    }

    printf("%d", r1+r2);

    return 0;
}