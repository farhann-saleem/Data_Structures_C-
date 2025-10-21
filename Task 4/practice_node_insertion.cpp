#include<iostream>
using namespace std;
int main(){
	
	struct Node{
		int data;
		Node* next;
	};
	
	Node* head= NULL;
	
	Node* nn= new Node;
	nn ->data=10;
	nn ->next=NULL;
	head=nn;
	
	Node* nn2=new Node;
	nn2 -> data=20;
	nn2 ->next=NULL; 
	head->next=nn;
	
	Node* nn3=new Node;
	nn3 -> data = 30;
	nn3 -> next=NULL;
	nn->next=nn3;
	
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

	
	
	return 0;
}