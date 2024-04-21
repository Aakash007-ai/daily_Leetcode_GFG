#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find that element in array if found return that index else -1
        //given array is sorted 
        // so we can reduce our searching space by half every time by comapring element with middle of searching space
        // i.e. binary search

        int s=0, e=nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]==target) return mid;
            else if(target > nums[mid]) s=mid+1;
            else e=mid-1;
        }
        return -1;
        
        
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    sort(nums.begin(),nums.end());
    int target = 0;
    cout << s.search(nums, target) << endl;
}