// count total number of nodes by traversing the linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL){
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("total nodes = %d", count);
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

    // here starting
    count_of_nodes(head);

    return 0;
}