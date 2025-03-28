#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
    printf("%d pushed to stack.\n", val);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", s->arr[s->top--]);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int main() {
    Stack s;
    init(&s);
    int ch, val;

    while (1) {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: ");
                    scanf("%d", &val);
                    push(&s, val);
                    break;
            case 2: pop(&s); break;
            case 3: peek(&s); break;
            case 4: display(&s); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
