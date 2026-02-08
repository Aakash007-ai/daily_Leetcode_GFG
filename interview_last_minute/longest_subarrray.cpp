#include<bits/stdc++.h>
using namespace std;

// [8,2,4,7], limit = 4
// so there we create a window of arrays having diff <= limit
// so if smallest and largest diff are in limit then array is compared with answered
// so we have to maintian the largest and smallest element in a data structure
// and for this we use priority_queue/heapify -> maxHeap and minHeap
// find the diff for every i/p
// so if diff is more than limit means Larger - smaller , either remove larger or smaller
// so whatever came first when moving window from left, so we have to store index along with larger/smaller
// if limit is greater find than that index to which window has to move
// move window by removing element from priority queue if our top element index is less than min/max index
class Solution {
public:
    priority_queue<pair<int,int>> maxHeap;//minheap
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int longLen = 0;
        int j=0;

        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
            maxHeap.push({nums[i],i});
            
            while(maxHeap.top().first - minHeap.top().first > limit){
                // now pop out element
                j = min(minHeap.top().second, maxHeap.top().second)+1;

                while(minHeap.top().second < j){
                    minHeap.pop();
                }

                while(maxHeap.top().second < j){
                    maxHeap.pop();
                }
                
            }
            longLen = max(longLen,i-j+1);
        }
        return longLen;
    }
};