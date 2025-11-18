    #include<iostream>
    using namespace std;
    int main(){

        int arr[]={34, 12, 56, 9, 22} ;
        int n=5;
        for (int i =0 ;  i <n  ; i ++ ){
            int min_index=i;

            for(int j =i+1 ; j<n ; j++){
                if (arr[j] <arr[min_index]){
                        min_index=j ;
                    }
            }
            
            int temp= arr[i];
            arr[i] = arr[min_index];
            arr[min_index]=temp;

            
        }
        for(int i=0 ; i <n ; i++){
            cout<<arr[i]<<endl;
        }

        return 0;
    }