#include<iostream>
using namespace std;
int main(){
	struct Node{
		int data;
		Node* next ;
	};
	Node* head = NULL;
	Node* nn= new Node;
	nn -> data=10 ;
	nn -> next=NULL;
	
	head=nn;
	cout<<"First node : "<<head->data<<endl;
	
	
	
	
	
	
	return 0;
}