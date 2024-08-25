#include <stdio.h>
#define MAX 5

// Deque structure
int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element at the front of the deque
void insertFront(int item) {
    // Check if the queue is full
    if ((front == 0 && rear == MAX - 1) || (front - 1) % MAX == rear) {
        printf("Queue is full\n");
    } else {
        // Insert the element at the front
        if (front == -1) { // If queue is initially empty
            front = 0;
            rear = 0;
        } else {
            front = (front - 1 + MAX) % MAX; // Added MAX to handle negative values
        }
        queue[front] = item;
        printf("Inserted %d to Front\n", item);
    }
}

// Function to insert an element at the rear of the deque
void insertRear(int item) {
    // Check if the queue is full
    if ((rear == MAX - 1 && front == 0) || (rear + 1) % MAX == front) {
        printf("Queue is full\n");
    } else {
        // Insert the element at the rear
        if (front == -1) { // If queue is initially empty
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("Inserted %d to Rear\n", item);
    }
}

// Function to delete an element from the front of the deque
void deleteFront() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d from Front\n", queue[front]);
        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Function to delete an element from the rear of the deque
void deleteRear() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d from Rear\n", queue[rear]);
        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + MAX) % MAX; // Added MAX to handle negative values
        }
    }
}

// Function to display the elements of the deque
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
    insertFront(10);
    insertFront(20);
    insertRear(30);
    insertRear(40);
    insertRear(50);
    insertFront(60);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}

// Output:
// Inserted 10 to Front
// Inserted 20 to Front
// Inserted 30 to Rear
// Inserted 40 to Rear
// Inserted 50 to Rear
// Queue is full
// Queue elements are:     20      10      30      40      50
// Deleted 20 from Front
// Queue elements are:     10      30      40      50
// Deleted 50 from Rear
// Queue elements are:     10      30      40