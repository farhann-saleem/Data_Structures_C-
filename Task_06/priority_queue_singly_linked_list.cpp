#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
    Node(int d, int p): data(d), priority(p), next(nullptr) {}
};

class PriorityQueue {
    Node* front; // smallest priority value at front
public:
    PriorityQueue(): front(nullptr) {}
    ~PriorityQueue() { while (front) { Node* t = front; front = front->next; delete t; } }

    bool isEmpty() const { return front == nullptr; }

    void enqueue(int data, int p) {
        Node* n = new Node(data, p);
        if (!front || p < front->priority) {
            n->next = front; front = n;
        } else {
            Node* cur = front;
            while (cur->next && cur->next->priority <= p) cur = cur->next; // FIFO for ties
            n->next = cur->next; cur->next = n;
        }
        cout << "Enqueued: (" << data << ", p=" << p << ")\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow! (Priority Queue is empty)\n"; return; }
        Node* t = front;
        cout << "Dequeued: (" << t->data << ", p=" << t->priority << ")\n";
        front = front->next; delete t;
    }

    void peek() const {
        if (isEmpty()) cout << "Priority Queue is empty.\n";
        else cout << "Front element: (" << front->data << ", p=" << front->priority << ")\n";
    }

    void display() const {
        if (isEmpty()) { cout << "Priority Queue is empty.\n"; return; }
        cout << "Priority Queue: ";
        for (Node* p = front; p; p = p->next) {
            cout << "(" << p->data << ",p=" << p->priority << ")";
            if (p->next) cout << " -> ";
        }
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    int ch, val, pr;
    cout << "==== Priority Queue using Linked List ====\n";
    while (true) {
        cout << "\n1.Enqueue(data,priority)  2.Dequeue  3.Peek  4.Display  5.Exit\nEnter choice: ";
        if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: cout << "Enter data and priority: "; cin >> val >> pr; pq.enqueue(val, pr); break;
            case 2: pq.dequeue(); break;
            case 3: pq.peek(); break;
            case 4: pq.display(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
