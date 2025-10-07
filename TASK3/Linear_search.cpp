#include<iostream>
using namespace std;
int main(){
	int arr[5]={1,2,3,4,5};
	int target;
	cout<<"Enter the value to search (1-5)"<<endl;
	cin>>target;
	bool found=false;
	for (int i=0 ; i<5 ;i++){
		if( arr[i] ==target){
			cout<<"Value founded at index "<<i<<endl;
			found=true;
			break;
		}

	}
	if(!found){
			cout<<"Value not founded"<<endl;
		};
		return 0;
}