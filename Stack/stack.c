# include <stdio.h>
# define MAX 5

int s[MAX];
int top = -1;

int push(int n){
    if(top != MAX-1){ // Check if Stack is not full
        top++;
        s[top] = n;
        printf("Pushed %d on Stack at Position %d\n",n,top+1);
    }else{
        printf("Stack is full\n");
    }
}

void pop(){
    if(top != -1){ // Check if Stack is not empty
        top--;
        printf("Popped %d from Stack\n",s[top+1]);
    }else{
        printf("Stack is empty\n");
    }
}

void display(){
    if(top == -1){
        printf("Stack is Empty\n");
    }else{
        printf("Stack:\n");
        for(int i = top; i>=0; i--){
            printf("%d\n",s[i]);
        }
    }
}

int main(){
    pop();
    push(1);
    push(2);
    push(3);
    pop();
    display(); 
    pop();
    pop();
    display();
}

// Output:

// Stack is empty
// Pushed 1 on Stack at Position 1
// Pushed 2 on Stack at Position 2
// Pushed 3 on Stack at Position 3
// Popped 3 from Stack
// Stack:
// 2
// 1
// Popped 2 from Stack
// Popped 1 from Stack
// Stack is Empty