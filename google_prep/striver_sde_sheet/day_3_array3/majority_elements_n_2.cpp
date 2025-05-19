#include<bits/stdc++.h>
using namespace std;

//find elements having occurances more than n/2 
class Solution {
    public:
        //brute force hasmap 

        //normal approach , element will be more than half
        int majorityElement(vector<int>& nums) {
            int count=0;
            int ele;

            for(auto it:nums){
                if(count==0){
                    ele =it;
                    count++;
                }else if(ele == it) count++;
                else{
                    count--;
                }
            }
            return ele;
        }
    };