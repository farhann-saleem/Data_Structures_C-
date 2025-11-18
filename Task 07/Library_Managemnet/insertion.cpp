/*
Scenario 1: Library Book Arrangement
A school library has received a batch of 20 new books that are in random order. The librarian wants to arrange them in ascending order based on the book ID numbers. Which sorting algorithm (Bubble, Selection, or Insertion) would be most suitable and why? Then perform the sorting on the sample list: [34, 12, 56, 9, 22].
*/

#include<iostream>
using namespace std;
int main(){

    int unsorted_list[]={34, 12, 56, 9, 22};
    int n=5;

    for (int i =0 ; i<n-1 ; i++){
        int min_index=i;

        for (int j=i+1 ; j<n ; j++){
            if(unsorted_list[j] < unsorted_list[min_index]){
                min_index=j;
            }
        }

        int temp = unsorted_list[i];
        unsorted_list[i]=unsorted_list[min_index];
        unsorted_list[min_index] = temp;

    }
    for (int i=0 ; i<n ; i++){
        cout<<unsorted_list[i]<<endl;
    }

    return 0;
}
