#include<iostream>
using namespace std;
int main(){
	int arr[6]={1,2,3,4,5};
	int n=5;
	for(int x:arr){
		cout<<x<<endl;
	}
	for(int i =n ; i>0; i--){
		arr[i]=arr[i-1];
	};
	int pos=0;
	int value=0;
	arr[pos]=value;
	n++;
	
	for (int x:arr){
		cout<<x<<endl;
	}
	
	
	
	return 0;
}