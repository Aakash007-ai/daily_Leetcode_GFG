#include<bits/stdc++.h>
using namespace std;
//array also get initialized as 0
// can an array be partiotioned into 2 equal subset sum 
class Solution{
public:
    bool solve(int n,int sum,int arr[]){
        if(sum==0) return true;
        if(n<=0) return false;

        if(sum >= arr[n-1]){
            return solve(n-1,sum - arr[n-1],arr) || solve(n-1,sum,arr);
        }
        return solve(n-1, sum, arr);
    }

    int equalPartition(int N, int arr[]){
        int sum = accumulate(arr, arr+N,0);
        if(sum%2) return 0; //we can't partiotioned it as sum of even can be partiotioned but not odd
        //else subset sum partiotioned with half sum
        return solve(N,sum/2,arr);
    }
};


int main(){
    int n;cin>>n;
    int arr[n]; //get initialized as 0
    // cout<<arr[0]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    cout<<obj.equalPartition(n,arr);
}