#include <stdio.h>
#include <stdlib.h>

//Define a node
struct Node
{
    int data;
    struct Node* next;
    
};

//Create a new node and return its address
struct Node* createNode(int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

//Print the linked list
void printList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("Null \n");
}

int main(){
    //create individual nodes
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    //link the nodes
    head->next = second;
    second->next = third;

    //print the list
    printf("Linked list: ");
    printList(head);
    return 0;
}
