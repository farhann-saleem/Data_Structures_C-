#include<iostream>
using namespace std;
int main(){
	int arr[5]={1 , 2 , 3 , 4 , 5};
	for( int x: arr){
		if(x%2==0){
			cout<<x<<endl;
		}
	}

	
	return 0 ;
}