#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        vector<int> diff;
        priority_queue<int> pq;
        for(int i=0;i<n-1;i++){
            diff.push_back(arr[n-1]-arr[i]);
            pq.push(arr[n-1]-arr[i]);
        }

        //now we have to find max num after checking -2k or 
        int mn=INT_MIN;
        while(!pq.empty()){
            int top=pq.top();pq.pop();


            
                                          
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    }
};