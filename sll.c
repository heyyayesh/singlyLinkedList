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

void traverse(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -----> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}