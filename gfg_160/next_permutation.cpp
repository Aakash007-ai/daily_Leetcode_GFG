#include<bits/stdc++.h>
using namespace std;

/* check this problem at last again its article
*/
class Solution {
    public:
    void nextPermutation(vector<int>& arr){
        next_permutation(arr.begin(),arr.end());
    }
    // complete your solution later
    //    void nextPermutation(vector<int>& arr) {
    //     int i=arr.size()-1;
    //     int mx=arr[i];
    //     while(i>=0){//first find the breaking point, means when smaller ele is present before bigger ele
    //         if(arr[i]<mx){
    //             break;
    //         }else{
    //             mx=arr[i];
    //         }
    //         i--;
    //     }
        
    //     // we got the point 
    //     if(i<0){
    //         reverse(arr.begin(),arr.end());
    //         return;
    //     }
        
    //     //find next bigger
    //     int sp=arr[i];
    //     sort(arr.begin()+i+1,arr.end());
    //     for(int j=i;j<arr.size();j++){
    //         // if(j<)
    //     }
    // }
};