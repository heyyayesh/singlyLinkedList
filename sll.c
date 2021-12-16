#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void createNodeAtEnd(int n);
void createNodeAtBeginning(int n);
void createNodeAtPosition(int n, int pos);

void deleteNodeAtEnd();
void deleteNodeAtBeginning();
void deleteNodeAtPosition(int pos);

void traverse();

int main(){
    createNodeAtEnd(100);
    createNodeAtEnd(200);

    createNodeAtBeginning(-100);
    createNodeAtBeginning(-200);

    createNodeAtPosition(0, 3);
    createNodeAtPosition(150, 5);

    deleteNodeAtEnd();
    deleteNodeAtBeginning();

    deleteNodeAtPosition(3);

    traverse();
}

void createNodeAtEnd(int n){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createNodeAtBeginning(int n){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = n;

    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void createNodeAtPosition(int n, int pos){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = n;

    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        struct node* temp = head;

        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeAtEnd(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
        return;
    }

    struct node* temp1 = head;
    struct node* temp2 = head;

    while(temp1->next != NULL){
        temp1 = temp1->next;
    }

    while(temp2->next != temp1){
        temp2 = temp2->next;
    }

    temp2->next = NULL;
    free(temp1);
}

void deleteNodeAtBeginning(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
}

void deleteNodeAtPosition(int pos){
    if(head == NULL){
        printf("Linked List is Empty.\n");
        return;
    }

    struct node* temp1 = head;
    struct node* temp2 = head;

    for(int i = 1; i < pos; i++){
        temp1 = temp1->next;
    }

    for(int i = 1; i < pos-1; i++){
        temp2 = temp2->next;
    }

    temp2->next = temp1->next;
    free(temp1);
}

void traverse(){
    if(head == NULL){
        printf("Linked List is Empty.\n");
        return;
    }

    struct node* temp = head;
    while(temp != NULL){
        printf("%d -----> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}