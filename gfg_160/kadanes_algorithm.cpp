#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    int maxSubArraySum(vector<int> &arr){
        int n=arr.size();
        int res=arr[0];
        int prefix = 0;

        for(int i=0;i<arr.size();i++){
            prefix += arr[i];
            if(prefix>=0){
                // prefix =  max(prefix,arr[i]);
                res = max(res,prefix);
            }else{
                res = max(arr[i],res);
                prefix=0;
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    // cout<<arr[2]<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    };
    // cout<<arr[2]<<endl;
    Solution obj;
    cout<<obj.maxSubArraySum(arr);
}