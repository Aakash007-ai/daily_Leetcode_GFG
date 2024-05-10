#include<bits/stdc++.h>
using namespace std;

//todo solve it in linear runtime
// Input: nums = [1,3,4,2,2]
// Output: 2
// 1 to 4 inclusive
// 5/2 =2 
// count ele less than 2
// 3 mid =2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //ok one is duplicate , so using binary serach reduce the searching space of number in 1 to n which can be duplicated
        int l=1,e=nums.size()-1;
        while(l<e){
            if(l==e) return l;
            int mid=l + (e-l)/2;

            int count=0;
            for(auto it:nums){//narrow down space , is number of elements more than mid are more or less
                if(it<=mid){
                    count++;
                }
            }
            
            if(count>mid) e=mid;
            else l=mid+1;


        }
        return l;
    }
};