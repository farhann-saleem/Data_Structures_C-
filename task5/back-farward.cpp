#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* next;
};

struct Node* backStack = NULL;
struct Node* forwardStack = NULL;

void push(struct Node** stack, char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = *stack;
    *stack = newNode;
}

char* pop(struct Node** stack) {
    if (*stack == NULL) return NULL;
    struct Node* temp = *stack;
    char* url = (char*)malloc(100);
    strcpy(url, temp->url);
    *stack = temp->next;
    free(temp);
    return url;
}

void visit(char* url) {
    push(&backStack, url);
    // Clear forward stack
    while (forwardStack != NULL) pop(&forwardStack);
    printf("Visited: %s\n", url);
}

void back() {
    if (backStack == NULL || backStack->next == NULL) {
        printf("No pages in history.\n");
        return;
    }
    char* current = pop(&backStack);
    push(&forwardStack, current);
    printf("Back to: %s\n", backStack->url);
    free(current);
}

void forward() {
    if (forwardStack == NULL) {
        printf("No forward pages.\n");
        return;
    }
    char* url = pop(&forwardStack);
    push(&backStack, url);
    printf("Forward to: %s\n", url);
    free(url);
}

void showHistory() {
    struct Node* temp = backStack;
    printf("Browsing History: ");
    while (temp != NULL) {
        printf("%s ", temp->url);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    visit("google.com");
    visit("youtube.com");
    visit("github.com");
    showHistory();
    back();
    showHistory();
    forward();
    showHistory();
    back();
    back();
    back(); // Underflow test
    return 0;
}
