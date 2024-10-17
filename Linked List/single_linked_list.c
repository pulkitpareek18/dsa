#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int info;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int info) {
    struct Node* newNode = createNode(info);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int info) {
    struct Node* newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node before a specific element
void insertBeforeElement(struct Node** head, int info, int target) {
    struct Node* newNode = createNode(info);
    
    // If the list is empty
    if (*head == NULL) {
        printf("List is empty. Cannot insert before %d.\n", target);
        free(newNode);
        return;
    }

    // If the target is the head
    if ((*head)->info == target) {
        insertAtBeginning(head, info);  // Reuse insertAtBeginning logic
        return;
    }

    // Traverse the list to find the node before the target
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->info != target) {
        prev = temp;
        temp = temp->next;
    }

    // If the target element is not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", target);
        free(newNode);
        return;
    }

    // Insert newNode before the target node
    prev->next = newNode;
    newNode->next = temp;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->info == key) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->info != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("Linked List: ");
    printList(head);

    insertBeforeElement(&head, 15, 20);  // Insert 15 before 20
    printf("Linked List after inserting 15 before 20: ");
    printList(head);

    deleteNode(&head, 20);
    printf("Linked List after deletion of 20: ");
    printList(head);

    return 0;
}


// Output:
// Linked List: 5 -> 10 -> 20 -> 30 -> NULL
// Linked List after inserting 15 before 20: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
// Linked List after deletion of 20: 5 -> 10 -> 15 -> 30 -> NULL