#include<iostream>
using namespace std;
int main(){
	int arr[6]={1,2,3,4,5};
	int n=5;
	for (int x: arr){
		cout<<x<<endl;
	}
	int pos=2;
	int value=20;
	for (int i=n ; i>pos ; i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=value;
	n++;
	
	for (int x: arr){
		cout<<x<<endl;
	}
	return 0;
}