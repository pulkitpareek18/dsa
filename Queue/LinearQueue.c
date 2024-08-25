#include <stdio.h>
#define MAX 5

// Declare an array to store the queue elements
int q[MAX];
// Initialize front and rear pointers to -1
int front = -1;
int rear = -1;

/**
 * Inserts an element into the queue
 * @param item the element to be inserted
 */
void insert(int item){
    // Check if the queue is full
    if(rear == MAX-1){
        printf("Queue is Full\n");
    }
    else{
        // If the queue is empty, set front to 0
        if(rear == -1){
            front = 0;
        }
        // Move the rear pointer to the next position
        rear++;
        // Store the item at the rear position
        q[rear] = item;
        printf("Added %d to Queue\n",q[rear]);
    }
}

/**
 * Deletes an element from the queue
 */
void delete(){
    // Check if the queue is empty
    if(front == -1){
        printf("Queue is Empty\n");
    }
    else{
        // Print the element being deleted
        printf("Deleted %d from Queue\n",q[front]);
        // Move the front pointer to the next position
        front++;
        // If the queue becomes empty, reset front and rear to -1
        if(front == MAX-1){
            front = -1;
            rear = -1;
        }
    }
}

/**
 * Displays the elements of the queue
 */
void display(){
    printf("Queue: ");
    // Iterate from front to rear and print the elements
    for(int i=front; i<=rear; i++){
        printf("%d\t",q[i]);
    }
    printf("\n");
}

int main(){
    // Insert elements into the queue
    insert(1);
    insert(2);
    // Display the queue
    display();
    // Delete an element from the queue
    delete();
    // Display the queue again
    display();
    return 0;
}

// Output
// Added 1 to Queue
// Added 2 to Queue
// Queue: 1        2
// Deleted 1 from Queue
// Queue: 2