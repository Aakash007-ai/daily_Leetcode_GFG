#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution{   
public:
    bool solve(int n,int sum,vector<int> &arr){
        if(sum==0) return true;
        if(n<=0) return false;

        if(sum >= arr[n-1]){
            return solve(n-1,sum - arr[n-1],arr) || solve(n-1,sum,arr);
        }
        return solve(n-1, sum, arr);
    }
    bool isSubsetSum(vector<int>arr, int sum){    
        int n=arr.size();
        return solve(n, sum,arr);
    }
};

int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // int x;
        // cin>>x;
        // arr[i]=x;
        // cout<<arr[i];
    }
    cin>>sum;
    Solution obj;
    cout<<obj.isSubsetSum(arr,sum);
}