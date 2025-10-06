#include<iostream>
using namespace std;
int main(){
	int arr[5]={0,1,2,3,4};
	int total=0;
	int average=0;
	
	for (int x :arr){
		total +=x;
	}
	average=total/5;
	
	cout<<total<<" "<<average<<endl;
	
	
	
	return 0;
}