#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kadaneAlgo(vector<int> &arr){
        int n = arr.size();
        int prefix = 0;
        int res = INT_MIN;
        int i = 0;
        while(i<n){
            prefix += arr[i];
            res = max(prefix,res);
            if(prefix<0) prefix=0;
            i++;
        }
        return res;
    }

    int circularSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int kadane = kadaneAlgo(arr);
        int acc = accumulate( arr.begin(), arr.end(),0);
        
    }
};

int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<obj.circularSubarraySum(arr);
}