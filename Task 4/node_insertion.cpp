#include<iostream>
using namespace std;
int main(){
	struct Node{
		int data;
		Node* next;
	};
	Node* head = NULL;
	Node* nn = new Node;
	nn ->data=10 ; 
	nn ->next=NULL ;
	head =nn;
	
	cout<<head->data<<endl; 
	
	Node* nn2=new Node;
	nn2 ->data=20;
	nn2 ->next =NULL;
	
	
	head->next=nn2;
	
	cout << "List: ";
    cout << head->data << " -> ";      // print first
    cout << head->next->data << " -> ";// print second
    cout << "NULL" << endl;
	
	
	
	
	
	return 0;
}