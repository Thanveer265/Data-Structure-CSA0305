#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int val) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = val;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack Empty\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("Stack Empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%d", &val);
            push(val);
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
        }
    } while (choice != 5);

    return 0;
}
