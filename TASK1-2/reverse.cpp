#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

int main(){
	int arr[5]={1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
	for (int x: arr){
		cout<<x<<endl;
	}
    // USING BUILT IN LIBRARRY 
	reverse(begin(arr) , end(arr) );	
//	int arr[5]={1,2,3,4,5};
cout<<"                           "<<endl;
	for (int x: arr){
		cout<<x<<endl;
	}
cout<<"                           "<<endl;
	


	return 0;
}