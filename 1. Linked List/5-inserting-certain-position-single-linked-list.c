#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

// add node at the end of the list
void add_at_end(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr = head;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// add at a certain position in the list
void add_at_pos(struct node* head, int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos!=1){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    int data = 67, position = 3;

    add_at_pos(head, data, position);
    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}