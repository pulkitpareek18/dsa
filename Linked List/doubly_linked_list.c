#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly linked list
struct Node {
    int info;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int info) {
    struct Node* newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
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
    newNode->prev = temp;
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

    // If the target element is the head
    if ((*head)->info == target) {
        insertAtBeginning(head, info); // Reuse the logic for inserting at the beginning
        return;
    }

    // Traverse the list to find the target element
    struct Node* temp = *head;
    while (temp != NULL && temp->info != target) {
        temp = temp->next;
    }

    // If target element is not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", target);
        free(newNode);
        return;
    }

    // Insert the new node before the target node
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If head node itself holds the key
    if (temp != NULL && temp->info == key) {
        *head = temp->next; // Changed head
        if (*head != NULL) {
            (*head)->prev = NULL; // Update prev pointer
        }
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->info != key) {
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // Update the next node's prev pointer
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next; // Update the previous node's next pointer
    }

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

// Function to print the linked list in reverse order
void printListReverse(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

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
// Linked List: 10 -> 20 -> 30 -> NULL
// Linked List after inserting 15 before 20: 10 -> 15 -> 20 -> 30 -> NULL
// Linked List after deletion of 20: 10 -> 15 -> 30 -> NULL