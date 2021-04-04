#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

// add node to list
void add_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;

    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// reversed the list of nodes
struct node* reverse(struct node *head){
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);
    add_at_end(head, 56);

    head = reverse(head);

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}