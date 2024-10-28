#include <stdio.h>

#define MAX 100 

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;  
int front2 = -1, rear2 = -1; 


void insert(int val) {
    if (rear1 == MAX - 1) {
        printf("Overflow in queue 1\n");
        return;
    }
    if (front1 == -1 && rear1 == -1) { 
        front1 = rear1 = 0;
    } else {
        rear1++;
    }
    q1[rear1] = val; 
}


void pop() {
    if (front1 == -1) { 
        printf("Underflow in queue 1\n");
        return;
    }
    int x = q1[front1]; 
    printf("Popped: %d\n", x);
    
    if (front1 == rear1) {
        front1 = rear1 = -1;
    } else {
        front1++;
    }
}


void dequeue() {
    if (front1 == -1) { 
        printf("Underflow in queue 1\n");
        return;
    }
    if (rear2 == MAX - 1) {
        printf("Overflow in queue 2\n");
        return;
    }
    
    if (front2 == -1 && rear2 == -1) { 
        front2 = rear2 = 0;
    } else {
        rear2++;
    }
    
    q2[rear2] = q1[front1];
    pop(); 
}


void displayQueue1() {
    if (front1 == -1) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", q1[i]);
    }
    printf("\n");
}


void displayQueue2() {
    if (front2 == -1) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = front2; i <= rear2; i++) {
        printf("%d ", q2[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    displayQueue1();
    
    dequeue();
    displayQueue1();
    displayQueue2();
    
    return 0;
}
