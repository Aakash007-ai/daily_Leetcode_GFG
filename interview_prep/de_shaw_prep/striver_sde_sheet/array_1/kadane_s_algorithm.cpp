#include<bits/stdc++.h>
using namespace std;


//maximum subarray
/*
    there  is an array of integers , return array with maximum sum
    constraints 1e5 so no dp (else dp is easy via recursion which cost us o(n**2))
    so we have to find subarray with maximum sum
    2 pointer approach or looking similar to variable size sliding window

    assume starting taking sum
    e.g. i=0,j=0; there are -ve num too so initially ans is 0
    case when a single elemnt comes after negative element then +ve element distinctly max

    start incrementing j , if arr
*/

/*
    so, assuming varaible size sliding window
    we need to find maximum sum window size

    start calculating ans , even with starting of window, 
    if sum become 0 then we can start another fresh window as we move

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],ans=nums[0],j=0;

        while(j<nums.size()){
            sum += nums[j++];

            ans = max(ans,sum);

            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};