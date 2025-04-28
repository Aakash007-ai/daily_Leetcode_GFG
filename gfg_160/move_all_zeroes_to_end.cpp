#include<bits/stdc++.h>
using namespace std;

// 1 2 0 4 3 0 5 0
// traverse over array with 2 pointer 1 pointing to first zero another pointing to next non zero
// traverse -> 
// if(arr[i]==0) 
// take position of that in j move next continue
// if (arr[j]==0 && arr[i]!= 0) swap(arr[i],arr[j])


class Solution {
    public : 
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=0, j=0;
        while(i<arr.size()){
            if(arr[i]==0){
                if(arr[j]==0){
                    i++;
                    continue;
                }
                j=i++;
            }else{
                if(arr[j]==0){
                    swap(arr[i],arr[j]);
                    j++;
                }
                i++;
            }
        }
    }
};