#include <stdio.h>
#include <stdlib.h>

struct Node {
    int plateNumber;
    struct Node* next;
};

struct Node* top = NULL;

void push(int plateNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->plateNumber = plateNumber;
    newNode->next = top;
    top = newNode;
    printf("Pushed plate %d\n", plateNumber);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No plates left.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped plate %d\n", temp->plateNumber);
    top = top->next;
    free(temp);
}

void display() {
    struct Node* temp = top;
    printf("Plates in dispenser: ");
    while (temp != NULL) {
        printf("%d ", temp->plateNumber);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(101);
    push(102);
    push(103);
    display();
    pop();
    display();
    pop();
    pop();
    pop(); // Underflow test
    return 0;
}
