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
        //printf("(%d ->next:%p)",temp->data,(void *)temp->next);
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("Null \n");
}

//insert a node at the end of the list
void insert_at_end(struct Node** head,struct Node* new_node){
    if (*head == NULL){
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL){
        
        temp = temp->next;
    }
    temp->next =new_node;
}

//insert a node at n position
void insert_at_position(struct Node** head, struct Node* new_node, int position){
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The previous node is null. Position is out of bounds.\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}


// Function to delete the last node of the list
void delete_last_node(struct Node** head) {
    if (*head == NULL) {
        // Empty list
        printf("List is already empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        // Only one node in the list
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second-last node
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete the last node and update second-last node's next to NULL
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at position n (1-based)
void delete_at_position(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* temp = *head;

    // If the head needs to be removed
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node before the one to delete
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    printf("Data of node to delete\n");
    printf("%d ",temp->next->data);

    // If position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    // Node temp->next is the one to delete
    struct Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}


// Function to search for a data value in the linked list
int search(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1; // Not found
}


int main(){
    //create individual nodes
    struct Node* head = createNode(10);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* new_node = createNode(5);
    struct Node* last_node = createNode(55);
    struct Node* mid_node = createNode(66);
    int position;

    //link the nodes
    head->next = second;
    second->next = third;

    //insert new_node at the begining
    new_node->next = head;
    head = new_node;

    //insert last_node at the end
    insert_at_end(&head,last_node);

    //insert in n position
    insert_at_position(&head,mid_node,3);
    

    //search for 55
    position = search(head,55);
    printf("Data found at : %d \n",position);



    //print the list
    printf("Linked list: ");
    printList(head);

    head = head->next;
    //print the list
    printf("\n Linked list after deletion: ");
    printList(head);

    //delete the last node
    delete_last_node(&head);

    //print the list
    printf("\n Linked list after deletion of last node: ");
    printList(head);

    //delete data of second position
    delete_at_position(&head,3);

    //print the list
    printf("\n Linked list after deletion of third node: ");
    printList(head);

    
    return 0;
}
