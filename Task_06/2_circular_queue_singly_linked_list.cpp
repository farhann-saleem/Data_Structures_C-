#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}  };

class CircularQueue {
    Node* front;
    Node* rear;
public:
    CircularQueue(): front(nullptr), rear(nullptr) {}
    bool isEmpty() const { return front == nullptr; }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (!front) { front = rear = n; rear->next = front; }
        else { rear->next = n; rear = n; rear->next = front; }
        cout << "Enqueued: " << value << "\n"; }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow! (Queue is empty)\n"; return; }
        if (front == rear) { cout << "Dequeued: " << front->data << "\n"; 
            delete front; front = rear = nullptr; }
        else {
            Node* t = front;
            cout << "Dequeued: " << t->data << "\n";
            front = front->next;
            rear->next = front;
            delete t; }  }

    void peek() const {
        if (isEmpty()) cout << "Queue is empty.\n";
        else cout << "Front element: " << front->data << "\n"; }

    void display() const {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        cout << "Circular Queue elements: ";
        Node* p = front;
        do { cout << p->data << " "; p = p->next; } while (p != front);
        cout << "\n"; } };

int main() {
    CircularQueue q;
    int ch, val;
    cout << "==== Circular Queue using Linked List ====\n";
    while (true) {
        cout << "\n1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\nEnter choice: ";
        if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n"; } } }
