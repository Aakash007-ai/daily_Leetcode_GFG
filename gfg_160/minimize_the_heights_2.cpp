#include<bits/stdc++.h>
using namespace std;
//retry this after some time

//we have to find the minimum height after modification of array such that height is minimum
// min height-------------------------------------max height
// so diff =    ----  min + k    -  max -k --------------
                  // ----------------------- = diff
// we just have to find this diff


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int res=arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-k<0) continue;
            
            int minL = min(arr[0]+k,arr[i]-k);
            int maxH = max(arr[n-1]-k,arr[i-1]+k);
            
            res = min(maxH-minL,res);
        }
        return res;
    }
};