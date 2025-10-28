// Part B: Restricted Queue modes using the same Deque
#include <iostream>
#include <string>
using namespace std;

struct Deque {
static const int MAX = 10;
int arr[MAX]; int front, rear, size;
Deque(): front(-1), rear(-1), size(0) {}
bool isEmpty(){return size==0;} bool isFull(){return size==MAX;}
void insertFront(int x){ if(isFull()){cout<<"Overflow!\n";return;}
     if(isEmpty()) front=rear=0; else front=(front-1+MAX)%MAX; arr[front]=x; size++; }

void insertRear(int x){ if(isFull()){cout<<"Overflow!\n";return;}
     if(isEmpty()) front=rear=0; else rear=(rear+1)%MAX; arr[rear]=x; size++; }

void deleteFront(){ if(isEmpty()){cout<<"Underflow!\n";return;} 
    if(front==rear){front=rear=-1; size=0;} else {front=(front+1)%MAX; size--;}}

void deleteRear(){ if(isEmpty()){cout<<"Underflow!\n";return;} 
    if(front==rear){front=rear=-1; size=0;} else {rear=(rear-1+MAX)%MAX; size--;}}
    
void display(){ if(isEmpty()){cout<<"[empty]\n";return;} cout<<"["; 
    for(int i=0;i<size;i++){int idx=(front+i)%MAX; cout<<arr[idx]; if(i!=size-1) cout<<", ";} cout<<"]\n"; }
};


int main(){
Deque q; int mode;
cout << "Select Mode: 1=Input-Restricted, 2=Output-Restricted\n";
mode = 1; // change to test both

// Example script for both modes
if(mode==1){
    // Input-Restricted: insert only at REAR
    q.insertRear(10); q.insertRear(20); q.display();
    // q.insertFront(5); // should be disabled in UI/menu
    q.deleteFront(); q.display();
    q.deleteRear(); q.display();
    } else if(mode==2){
    // Output-Restricted: delete only at FRONT
    q.insertRear(11); q.insertFront(999); q.display();
    // q.deleteRear(); // should be disabled in UI/menu
    q.deleteFront(); q.display();
}
return 0;
}