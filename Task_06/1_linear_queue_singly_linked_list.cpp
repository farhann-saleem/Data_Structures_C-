#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue(): front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* n = new Node(value);
        if (!front) { front = rear = n; }
        else { rear->next = n; rear = n; }
        cout << "Enqueued: " << value << "\n";
    }

    void dequeue() {
        if (!front) { cout << "Queue Underflow! (Queue is empty)\n"; return; }
        Node* t = front;
        cout << "Dequeued: " << t->data << "\n";
        front = front->next;
        if (!front) rear = nullptr;
        delete t;
    }

    void peek() const {
        if (!front) cout << "Queue is empty.\n";
        else cout << "Front element: " << front->data << "\n";
    }

    void display() const {
        if (!front) { cout << "Queue is empty.\n"; return; }
        cout << "Queue elements: ";
        for (Node* p = front; p; p = p->next) cout << p->data << " ";
        cout << "\n";
    }
};

int main() {
    Queue q;
    int ch, val;
    cout << "==== Linear Queue using Linked List ====\n";
    while (true) {
        cout << "\n1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\nEnter choice: ";
        if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
