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

// delete list
struct node* del_list(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);
    add_at_end(head, 56);

    head = del_list(head);
    if(head == NULL){
        printf("Linked list deleted successfully");
    }

    return 0;
}