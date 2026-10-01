#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int data) {
    if (isFull()) {
        printf("overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

void pop() {
    if (isEmpty()) {
        printf("underflow\n");
        return;
    }
    top--;
}

void peek() {
    if (isEmpty()) {
        printf("no ele\n");
        return;
    }
    printf("%d\n", stack[top]);
}

void display() {
    if (isEmpty()) {
        printf("stack empty\n");
        return;
    }
    int i = top;
    while (i >= 0) {
        printf("%d ", stack[i]);
        i--;
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
