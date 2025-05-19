#include<bits/stdc++.h>
using namespace std;

//so brute force , find all the permutation , then get the next , but how can we find all the permutation
//sorted is the initial element
// [1,2,3] , []

// next permutation
//[1,2,3] -> [1,3,2]
//[2,3,1] -> [3,2,1]
//[1,3,2] -> [3,1,2] false it should be [2,1,3]
// [3,2,1] -> [3,2,1] -> reverse it again

//it means, if we traverse from last thenput the check if current top element is less than max then reverse it
// so we can just iterate from back and find the max element in comparesion with curr i
// if there is an element swap it, and once swap return arrray as it is

//so put all in stack [1,2,3]
// int max=int_min

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         //so next permutation means finding the next greatest number 
//         // means somewhere there is an element at any index which have next greater element
//         // so first find the next greater element

//         int j=nums.size()-1;
//         // int nextGreaterEle = nums[j]; //means smallest element
//         // int nextGreaterIdx = j;
//         pair<int,int> nextSmallEle = {nums[j],j}; //element ,index
//         j--;
//         while(j>=0){
//             if(nums[j]<nextSmallEle.first){ 
//                 //we found the smallest element before greatest, so greatest will take its place and sort rest of array
//                 // swap(nums[j],nums[nextSmallEle.second]);
//                 // sort(nums.begin()+j+1,nums.end());
//                 break;
//             }
//             else {
//                 // 3 1 2 0  -> 3 2 0 1
//             }
//         }
//     }
// };



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //so --increasing-->  top    <---increasing---- here replace top with next greatest
        // e.g. 5 6 8 7 4
        int n=nums.size();
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        //find the next greatest
        for(int i=n-1;i>index && index!= -1;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
    }
};
