#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    void swapElements(int arr[], int n){
        for(int i=0;i<n-2;i++){
            // swap(arr+i,arr+i+2);
            int temp=arr[i];
            arr[i]=arr[i+2];
            arr[i+2]=temp;

        }      
        // Your code here
        
    }
};