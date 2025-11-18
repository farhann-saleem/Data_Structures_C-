#include<iostream>
using namespace std;

int main(){

    int arr[] = {45, 78, 50, 89, 60};
    int n = 5;

    for (int i =1 ; i < n ; i ++){
        int key = arr[i];
        int j = i -1 ;




        while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];  // shift element to the right
        j--;                  // move left
        
    }
    arr[j+1] = key;
    

}

for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;


    return 0;
}
