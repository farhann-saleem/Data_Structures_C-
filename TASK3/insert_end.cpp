#include<iostream>
using namespace std;
int main(){
	int arr[6]={1,2,3,4,5};
	int n=7;
	int pos=5;
	for(int x:arr){
		cout<<x<<endl;
	}

	int value=6;
	arr[pos]=value;
	n++;
	
	for (int x:arr){
		cout<<x<<endl;
	}
	
	
	
	return 0;
}