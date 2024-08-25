#include <stdio.h>
#define MAX 5

// Circular queue structure
int queue[MAX];
int front = -1, rear = -1;

/**
 * Inserts an element into the queue
 * @param item The element to be inserted
 */
void insert(int item) {
    // Check if the queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else {
        // If the queue is initially empty, set front and rear to 0
        if (front == -1) {
            front = 0;
        }
        // Move the rear pointer to the next position
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("Inserted item is %d\n", item);
    }
}

/**
 * Deletes an element from the queue
 */
void delete() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted item is %d\n", queue[front]);
        // If there is only one element, reset front and rear to -1
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Move the front pointer to the next position
            front = (front + 1) % MAX;
        }
    }
}

/**
 * Displays the elements in the queue
 */
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\t");
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d\t", queue[i]);
        }
        printf("%d\t\n", queue[i]);
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60); // This will fail because the queue is full
    display();
    delete();
    insert(60);
    display();
    return 0;
}

// Output: 
// Inserted item is 10
// Inserted item is 20
// Inserted item is 30
// Inserted item is 40
// Inserted item is 50
// Queue is full
// Queue elements are:     10      20      30      40      50
// Deleted item is 10
// Inserted item is 60
// Queue elements are:     20      30      40      50      60