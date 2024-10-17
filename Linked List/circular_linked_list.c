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
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;  // Point to itself to make it circular
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;  // Move the head to the new node
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int info) {
    struct Node* newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;  // Point to itself to make it circular
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;  // Complete the circular link
    }
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

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->info != target);

    // If the target element is not found
    if (temp->info != target) {
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
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp->info == key) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;  // Only one node, set head to NULL
            return;
        }

        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->info != key);

    // If key was not present in the list
    if (temp->info != key) return;

    prev->next = temp->next;
    free(temp);
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to demonstrate the circular linked list operations
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("Circular Linked List: ");
    printList(head);

    insertBeforeElement(&head, 25, 20);  // Insert 25 before 20
    printf("After inserting 25 before 20: ");
    printList(head);

    deleteNode(&head, 20);
    printf("Circular Linked List after deletion of 20: ");
    printList(head);

    return 0;
}

// Output:
// Circular Linked List: 5 -> 10 -> 20 -> 30 -> (head)
// After inserting 25 before 20: 5 -> 10 -> 25 -> 20 -> 30 -> (head)
// Circular Linked List after deletion of 20: 5 -> 10 -> 25 -> 30 -> (head)