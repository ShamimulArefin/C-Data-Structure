// method 1 using two pointer
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

// delete last node from the list
struct node* del_last(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != NULL){
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    head = del_last(head);

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}


// method 2 using single pointer
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

// delete last node from the list
void del_last(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    del_last(head);

    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}