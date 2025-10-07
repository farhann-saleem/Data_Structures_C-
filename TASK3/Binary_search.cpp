#include<iostream>
using namespace std;
int main(){
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int n=10;
	int target;
	cout<<"Enter the value to search for (1-10)"<<endl;
	cin>>target;
	bool found=false;
	int low=0;
	int high=n-1;
	int index=-1;
	
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==target){
		found=true;
		index=mid;	
		break;
		}else if(arr[mid]<target){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	if(found){
		cout<<"found at index "<<index<<endl;
	}else{
		cout<<"not found"<<endl;
	}
	
	return 0;
}