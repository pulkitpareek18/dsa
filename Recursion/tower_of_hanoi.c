# include <stdio.h>

char source = 'A', auxilary = 'B', destination = 'C';
void hanoi(int n, char source, char auxilary, char destination){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", source, destination);
    }
    else{
        hanoi(n-1, source, auxilary, destination);
        printf("Move disk %d from %c to %c\n", n, source, destination);
        hanoi(n-1, auxilary, source, destination);
    }

}
int main(){
    hanoi(3, source, auxilary, destination);
    return 0;
}

// Output
// Move disk 1 from A to C
// Move disk 2 from A to C
// Move disk 1 from B to C
// Move disk 3 from A to C
// Move disk 1 from B to C
// Move disk 2 from B to C
// Move disk 1 from A to C