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

// delete first node
struct node* del_first(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else{
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    head = del_first(head);

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}