#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode {
    int data;
    struct Dnode* prev;
    struct Dnode* next;
}Dnode;

void insert_at_begining(Dnode** head, int data){
    Dnode* new_node = (Dnode*)malloc(sizeof(Dnode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if(*head != NULL){
        (*head)->prev = new_node;
    }
    *head = new_node;

}


int main(){
    Dnode* head = NULL;
    insert_at_begining(&head, 10);
    
    // Simple print to verify:
    Dnode* temp = head;
    while (temp != NULL) {
        printf("%p <- %d -> %p \n",(void*)temp->prev,temp->data,(void*)temp->next);
        temp = temp->next;
    }
    printf("NULL\n");


    insert_at_begining(&head, 20);

    // Simple print to verify:
    Dnode* temp1 = head;
    while (temp1 != NULL) {
        printf("%p <- %d -> %p \n",(void*)temp1->prev,temp1->data,(void*)temp1->next);
        temp1 = temp1->next;
    }
    printf("NULL\n");

    insert_at_begining(&head, 20);

    // Simple print to verify:
    Dnode* temp2 = head;
    while (temp2 != NULL) {
        printf("%p <- %d -> %p \n",(void*)temp2->prev,temp2->data,(void*)temp2->next);
        temp2 = temp2->next;
    }
    printf("NULL\n");

    return 0;
}
