// Part A: Circular Array Deque (Parking Lot)
#include <iostream>
using namespace std;

struct Deque {
static const int MAX = 10; // change if needed
int arr[MAX];
int front, rear, size;

Deque(): front(-1), rear(-1), size(0) {}

bool isEmpty() { return size == 0; }
bool isFull() { return size == MAX; }

void insertFront(int x) {
    if (isFull()) { cout << "Overflow: Parking full!"<<endl; return; }
    if (isEmpty()) front = rear = 0;
        else front = (front - 1 + MAX) % MAX;
    arr[front] = x; size++;
    cout << "Car " << x << " entered from NORTH."<<endl; }

void insertRear(int x) {
    if (isFull()) { cout << "Overflow: Parking full!"<<endl; return; }
    if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % MAX;
    arr[rear] = x; size++;
    cout << "Car " << x << " entered from SOUTH."<<endl; }


void deleteFront() {
    if (isEmpty()) { cout << "Underflow: No cars!"<<endl; return; }
    int x = arr[front];
    if (front == rear) { front = rear = -1; size = 0; }
        else { front = (front + 1) % MAX; size--; }
    cout << "Car " << x << " left from NORTH."<<endl; }


void deleteRear() {
    if (isEmpty()) { cout << "Underflow: No cars!"<<endl; return; }
    int x = arr[rear];
    if (front == rear) { front = rear = -1; size = 0; }
        else { rear = (rear - 1 + MAX) % MAX; size--; }
    cout << "Car " << x << " left from SOUTH."<<endl;
}


void display() {
    if (isEmpty()) { cout << "[empty]"<<endl; return; }
        cout << "Parking (Front->Rear): [";
    for (int i = 0; i < size; ++i) {
    int idx = (front + i) % MAX;
    cout << arr[idx];
    if (i != size - 1) cout << ", "; }
        cout << "]"<<endl; } };

int main() {
    Deque dq;
    dq.insertRear(101);
    dq.insertRear(102);
    dq.insertFront(999);
    dq.display();       
    dq.deleteRear();
    dq.display();
    dq.deleteFront();
    dq.display();
    return 0;
}