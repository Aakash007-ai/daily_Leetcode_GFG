#include<bits/stdc++.h>
using namespace std;

// brute froce 
// O(n^2) time complexity
// O(1) space complexity
// nested for loop , for each element check how many times it occurs

// using hasing
// O(n) time complexity
// O(n) space complexity
// use a hash map to store the count of each element

// using moore's voting algorithm
// O(n) time complexity
// class Solution {
//     public:
//         vector<int> majorityElement(vector<int>& nums) {
//             int num1=0;
//             int cnt1=0;

//             int num2=0;
//             int cnt2=0;
//             for(int i=0;i<nums.size();i++){
//                 if(num1 ==0){
//                     num1=num1;
//                     cnt1++;
//                 }else if(num2 == 0){
//                     num2=nums[i];
//                     cnt2++;
//                 }else if(num1 == nums[i]){
//                     cnt1++;
//                 }else if(num2 == nums[i]){
//                     cnt2++;
//                 }else{
//                     cnt1--;
//                     cnt2--;
//                 }
//             }


//             vector<int> ans;
//             cnt1=0;
//             cnt2=0;
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i] == num1){
//                     cnt1++;
//                 }else if(nums[i] == num2){
//                     cnt2++;
//                 }
//             }

//             if(cnt1 > nums.size()/3){
//                 ans.push_back(num1);
//             }
//             if(cnt2 > nums.size()/3){
//                 ans.push_back(num2);
//             }

//             return ans;
//         }
//     };

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int majority1 = 0;
            int majority2 = 0;
            int count1 = 0;
            int count2 = 0;
    
            for (const int num : nums) {
                if (num == majority1) {
                    count1++;
                } else if (num == majority2) {
                    count2++;
                } else if (count1 == 0) {
                    majority1 = num;
                    count1++;
                } else if (count2 == 0) {
                    majority2 = num;
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            }
    
            count1 = 0;
            count2 = 0;
    
            for (const int num : nums) {
                if (num == majority1) {
                    count1++;
                } else if (num == majority2) {
                    count2++;
                }
            }
    
            std::vector<int> res;
    
            if (count1 > nums.size() / 3) {
                res.push_back(majority1);
            }
            if (count2 > nums.size() / 3) {
                res.push_back(majority2);
            }
    
            return res;        
        }
    };