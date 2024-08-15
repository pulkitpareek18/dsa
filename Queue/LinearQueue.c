# include <stdio.h>
# define MAX 5

int q[5];
int front = -1;
int rear = -1;

void insert(int item){
    if(rear == MAX-1){
        printf("Queue is Full\n");
    }
    else{
        if(rear == -1){
            front = 0;
        }
        rear++;
        q[rear] = item;
        printf("Added %d to Queue\n",q[rear]);
    }
}

void delete(){
    if(front == -1){
        printf("Queue is Empty\n");
    }
    else{
        printf("Deleted %d from Queue\n",q[front]);
        front++;
        if(front == MAX-1){
            front = -1;
            rear = -1;
        }
    }
}

void display(){
    printf("Queue: ");
    for(int i=front; i<=rear; i++){
        printf("%d\t",q[i]);
    }
}

int main(){
    insert(1);
    insert(2);
    display();
    delete();
    display();
    return 0;
}