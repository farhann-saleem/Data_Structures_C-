#include<iostream>
using namespace std;
int main(){
	int arr[5]={1,2,2,3,4};
	bool found=false;
	int count=0;
	int target;
	cout<<"Enter your desired value(1-4)"<<endl;
	cin>>target;
	for (int i =0 ; i<5 ; i++){
		if(arr[i]==target){
			cout<<"Value founded at "<<i<<endl;
			count++;
			found=true;
		}
	}
	if (!found) {
        cout << "Value not found"<<endl;
    } else {
        cout << "Total occurrences: "<<count<<endl;
    }

	return 0;
}