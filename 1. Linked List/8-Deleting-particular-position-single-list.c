
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

// add node to end
void add_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr=head;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// delete node from the list at a particlular position
void del_pos(struct node **head, int position){
    struct node *current = *head;
    struct node *previous = *head;
    if(*head == NULL){
        printf("List is already empty!");
    }
    else if(position == 1){
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(position != 1){
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    int position = 2;
    del_pos(&head, position);

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}