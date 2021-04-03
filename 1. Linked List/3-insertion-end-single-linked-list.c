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

int main(){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link = current;

    current = (struct node *) malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    // add node at the end of the list
    add_at_end(head, 67);
    return 0;
}


// optimize the code O(1), before it was O(n)
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link = temp;
    return temp;
};

int main(){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr, 98);
    ptr = add_at_end(ptr, 3);
    ptr = add_at_end(ptr, 67);

    ptr = head;

    printf("Data = ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}