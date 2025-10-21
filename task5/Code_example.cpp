#include <iostream>
using namespace std;

struct Node {
	 int data;
	 Node *next;
	 };
Node *top = NULL;
// Function to check if stack is empty
bool isempty() {
 	return (top == NULL);}
// Function to insert an element in stack
void push(int value) {
	 Node *ptr = new Node();
	 ptr->data = value;
	 ptr->next = top;
	 top = ptr;}
// Function to delete an element from stack
void pop() {
 if (isempty())
	 cout << "Stack is Empty\n";
 else {
	 Node *ptr = top;
	 top = top->next;
 delete(ptr); } }
// Function to show the top element
void showTop() {
	 if (isempty())
	 	cout << "Stack is Empty\n";
	 else
	 	cout << "Element at top is: " << top->data <<endl;
		  }
	// Function to display the stack
void displayStack() {
	 if (isempty())
	 cout << "Stack is Empty\n";
	 else {
	 Node *temp = top;
	 while (temp != NULL) {
	 cout << temp->data << " ";
	 temp = temp->next; }
	 cout << endl;
	 }
	  }
// Main function
int main() {
 int choice, flag = 1, value;
 while (flag == 1) {
 cout << "\n1.Push 2.Pop 3.showTop
4.displayStack 5.Exit\n";
 cin >> choice;
 switch (choice) {
	 case 1:
		cout << "Enter Value: ";
		cin >> value;
		push(value);
	 	break;
	 case 2:
		 pop();
		 break;
	 case 3:
		 showTop();
		 break;
	 case 4:
		 displayStack();
		 break;
	 case 5:
		 flag = 0;
	 break;
		 default:
	 cout << "Invalid Choice!\n";
	 }}
 return 0;
 }
 
 
 