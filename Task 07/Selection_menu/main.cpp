#include <iostream>
using namespace std;
//  3 functions 
// bubble sort comapring 2 values iwth neighnours ones and swap it accordingly 

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){

        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// one is selected


void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int choice;
    cout << "----- Sorting Menu -----"<<endl;
    cout << "1. Bubble Sort"<<endl;
    cout << "2. Selection Sort"<<endl;
    cout << "3. Insertion Sort"<<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;

    int n;
    cout << "Enter number of elements: "<<endl;
    cin >> n;

    int arr[100];
    cout << "Enter the elements:"<<endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    switch(choice){
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        default:
            cout << "Invalid choice!"<<endl;
            return 0;
    }

    cout << "Sorted array: "<<endl;
    printArray(arr, n);

    return 0;
}
