#include <stdio.h>
#include <ctype.h>

#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* exp) {
    int i = 0;
    char c;
    while ((c = exp[i++]) != '\0') {
        if (isalnum(c)) printf("%c", c);
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("Postfix: ");
    infixToPostfix(exp);
    return 0;
}
