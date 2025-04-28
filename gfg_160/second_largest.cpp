#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int max = arr[0];
        int ans = INT_MIN;
        
        for(int i=1;i<arr.size();i++){
            if(max < arr[i]){
                ans = max;
                max=arr[i];
            }else if(ans < arr[i] && arr[i]!= max){
                ans=arr[i];
            }
        }
        if(ans == INT_MIN) ans=-1;
        return ans;
    }
};