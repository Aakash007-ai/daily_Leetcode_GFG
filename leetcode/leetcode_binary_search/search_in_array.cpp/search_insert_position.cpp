#include<bits/stdc++.h>
using namespace std;

//1 3 5 6  //5,2,7
// 5 will give ans
//for 0 s=0 e=-1 ans is s //left out of bound ans is s w
//for 2 s=1 ,e=0 ans is s //else ans is s for every other case
//for 7 s=4 e=3 ans is e //s out of bound


//so if you don't decide the boundary case just write normal code and then traverse over a small example


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //retrun idx if found else return index wehere it can be put
        //so while putting it must be put to next where the element is less than target
        // so if that index is leftmost s=-1 e=0
        // so if that index is last s=out of bound e=last
        // inbetween 2 3 5 7 ans is end s or end  it may be end  (do a brute force and check end is that index)

        int s=0, e=nums.size()-1;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) s=mid+1;
            else e=mid-1;
        }

        if(e==-1) return 0;
        if(s==nums.size()) return nums.size();

        return s;
    }
};