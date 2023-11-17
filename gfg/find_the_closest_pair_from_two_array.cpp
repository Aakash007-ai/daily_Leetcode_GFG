#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i=0,j=m-1;
        int mn=INT_MAX;
        vector<int> ans;
        while(i<n && j>=0){
            int sum=arr[i]+brr[j];
            int diff =abs( x-sum);
            if(diff==0) return {arr[i],brr[j]};
            if(diff<mn){
                mn = diff;
                ans={arr[i],brr[j]};
            }
            if(sum<x) i++;
            else j--;
        }
        return ans;
    }
};


int main(){
    int n,m,x;
    cin>>n>>m;
    int arr[n],brr[m];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<m;j++){
        cin>>brr[m];
    }

    cin>>x;

    Solution obj;
    vector<int> ele=obj.printClosest(arr,brr,n,m,x);
}