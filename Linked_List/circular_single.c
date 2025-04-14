#include <stdio.h>
#include <stdlib.h>

//Definition
typedef struct CNode{
    int data;
    struct CNode* next;
}CNode;

//Creation
CNode* create_node(int data){
    CNode* new_node = (CNode*)malloc(sizeof(CNode));
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

//Insert
void insert_at_position(CNode** head, int data, int position){
    CNode* new_node = (CNode*)malloc(sizeof(CNode));
    new_node->data = data;

    if(*head == NULL){
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    if(position == 0){
        CNode* temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }

        new_node->next = *head;
        temp->next = new_node;
        *head = new_node;
        return;
    }

    CNode* temp = *head;
    int count = 0;
    while(count < position - 1 && temp->next != *head){
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}
//Deletion
void delete_at_position(CNode** head, int position){
    if(*head == NULL){
        printf("Empty list");
    }

    CNode* temp = *head;
    //Delete the head node
    if(position == 0){
        //if there is only one node
        if(temp->next == *head){
            free(temp);
            *head = NULL;
            return;
        }

        //For more than one node
        CNode* last = *head;
        while(last->next != *head){
            last = last->next;
        }

        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }
    //traverse to the node before the one we want to delete
    int count=0;
    while(count<position-1 && temp->next !=*head){
        temp = temp->next;
        count++;
    }

    //if the position is out of bounds
    if(temp->next == *head || temp->next == NULL){
        printf("Position is out of bounds");
    }

    CNode* del = temp->next;
    temp->next = del->next;
    free(del);

}


void print_cnode(CNode *head){
    if (head == NULL) return;

    CNode* temp = head;
    do {
        printf("%d -> %p\n", temp->data, (void*)temp->next);
        temp = temp->next;
    } while(temp != head);
}

int main(){
    CNode* head = NULL;
    insert_at_position(&head,5,0);
    insert_at_position(&head,6,1);
    insert_at_position(&head,7,2);
    insert_at_position(&head,8,3);
    insert_at_position(&head,9,0);

    printf("Circular singly linked list\n");
    print_cnode(head);

    printf("Deletion in process \n");
    delete_at_position(&head,2);
    print_cnode(head);
    printf("Deleting again\n");
    delete_at_position(&head,1);
    print_cnode(head);
    return 0;
}
