#include<iostream>
using namespace std;
int main(){
	int arr[5]={1,2,3,4,5};
	int n=5;
	int pos=2;
	int val=0;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

	for(int i =0 ; i <pos ; i--){
		arr[i]=arr[i-1];
	}
	arr[pos]=val;
	n++;
	
	for (int x: arr){
		cout<<x<<endl;
	}

	return 0;}
