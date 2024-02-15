#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount=0;
        for(auto it: nums){
            if(it==0) return 0;
            else if(it<0) ++negCount;
        }
        return negCount % 2 ? 1 :-1;
    }
};


int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // for(auto it:arr){
    //     cout<<it<<" ";
    // }


    Solution obj;
    cout<<obj.arraySign(arr);
}