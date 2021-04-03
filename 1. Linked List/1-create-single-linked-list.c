// create a single linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main(){
    // first node
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    // second node
    struct node *current = (struct node *) malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    // current(2nd node) locate to head link null
    head->link = current;

    // third node; reusing current pointer
    current = (struct node *) malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    // point 3rd node to 2nd node null area
    head->link->link=current;

    return 0;
}