#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

// count total number of nodes
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
    printf("total nodes = %d\n", count);
}

// printing Data
void print_data(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    printf("Data = ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
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

    // counting nodes
    count_of_nodes(head);
    
    // printing Data
    print_data(head);

    return 0;
}