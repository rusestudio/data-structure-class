#include <stdio.h>
#include <stdlib.h>

struct Node {
    int ballon;
    int step;
    struct Node *next;
    struct Node *prev;
};

int main(){

    int b;
    scanf("%d", &b);

    struct Node *head_ptr = NULL;
    struct Node *tail_ptr = NULL;

    int s;
    for(int i = 1; i <= b; i++){
        scanf("%d",&s);

        struct Node *new_data = (struct Node*)malloc(sizeof(struct Node));
        if (new_data == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        

        (*new_data).ballon = i;
        (*new_data).step = s;

        if(head_ptr== NULL){
            head_ptr = new_data;
            tail_ptr = new_data;
            new_data->next = new_data;
            new_data->prev = new_data;
        }else{
            new_data->prev = tail_ptr;
            new_data->next = head_ptr; 
            tail_ptr->next = new_data;
            head_ptr->prev = new_data;
            tail_ptr = new_data;
            
        }    
    }
    //
    struct Node *current = head_ptr;

    for(int i =0; i < b; i++){
        printf("%d ", (*current).ballon);//print current ballon after pop in this loop

        if (i ==  b -1){
            free(current);
            break;
        }

        int move = current->step;
        struct Node *c_next = current->next;
        struct Node *c_prev = current->prev;

        if(current->next == current){
            free(current);
            head_ptr= NULL;
            break;
        } else {
            c_next->prev = c_prev;
            c_prev->next = c_next;
            if(current == head_ptr){
                head_ptr = c_next;
            }
        }
        free(current);

        if(move > 0){
            current = c_next;
            for(int j = 1; j < move; j++){
                current = current->next;
            }
        }else{
            current = c_prev;
            for(int j = 1; j < -move; j++){
                current = current->prev;
            }
        }
        
    }
    return 0;
}