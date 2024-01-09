#include<bits/stdc++.h>
using namespace std;

//find whether we can divide an array to every pair divisible by k

//so , sum of that is divisible by k
// i+j % k == 0
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        //if size of array is odd we can't divide it in pairwise      
        if(nums.size()%2!=0) return false;
        
        unordered_set<int> s;
        int count=0;

        //let's iterate over array
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0) count++; //we have a num which is divisible by k count ++;
            else{
                int rem=nums[i]%k;//let's find how much rem we get (num to be added to get divible by k)
                if(s.find(k-rem)==s.end()){
                    s.insert(rem);
                }
                else{
                    s.erase(k-rem);
                }
            }
        }
        return s.size()==0 && count%2==0;
      
        
    }
};