#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode {
    int data;
    struct Dnode* prev;
    struct Dnode* next;
}Dnode;

void insert_at_pos(Dnode** head, int data, int position) {
    Dnode* new_node = (Dnode*)malloc(sizeof(Dnode));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (position == 0 || *head == NULL) {
        // Insert at beginning or if list is empty
        new_node->next = *head;
        if (*head != NULL)
            (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Dnode* temp = *head;
    int count = 0;

    // Traverse to the node just before the desired position
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
        
    }

   

    if (count < position - 1) {
        // If position is out of bounds, insert at the end
        printf("Position out of bounds. Node appended at the end.\n");
    }

    // Insert after the current temp node (which is the last or valid position)
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
}


void delete_at_pos(Dnode** head, int position) {
    if (*head == NULL) {
        return;
    }

    Dnode* temp = *head;

    // Deleting the head node
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    int count = 0;
    // Traverse to the node at the given position
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        // Position out of bounds
        return;
    }

    // Unlink the node from the list
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}



void print_list(Dnode* head){
    Dnode* temp2 = head;
    while (temp2 != NULL) {
        printf("%p <- %d -> %p \n",(void*)temp2->prev,temp2->data,(void*)temp2->next);
        temp2 = temp2->next;
    }
    printf("NULL\n");
}

int main(){
    Dnode* head = NULL;
    insert_at_pos(&head, 10,1);
    
    // Simple print to verify:
    Dnode* temp = head;
    while (temp != NULL) {
        printf("%p <- %d -> %p \n",(void*)temp->prev,temp->data,(void*)temp->next);
        temp = temp->next;
    }
    
    insert_at_pos(&head, 20,1);
    // Simple print to verify:
    print_list(head);

    insert_at_pos(&head,30,1);
    print_list(head);

    insert_at_pos(&head,40,2);
    print_list(head);

    insert_at_pos(&head,50,2);
    print_list(head);

    insert_at_pos(&head,400,20);
    print_list(head);

    delete_at_pos(&head,2);
    print_list(head);

    delete_at_pos(&head,1);
    print_list(head);


   

    return 0;
}
