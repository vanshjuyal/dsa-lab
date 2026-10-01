#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("overflow\n");
        return;
    }
    p->data = data;
    p->next = top;
    top = p;
}

void pop() {
    if (isEmpty()) {
        printf("underflow\n");
        return;
    }
    struct node *d = top;
    top = top->next;
    free(d);
}

void peek() {
    if (isEmpty()) {
        printf("no ele\n");
        return;
    }
    printf("%d\n", top->data);
}

void display() {
    if (isEmpty()) {
        printf("stack empty\n");
        return;
    }
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
