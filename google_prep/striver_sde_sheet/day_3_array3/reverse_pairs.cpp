#include<bits/stdc++.h>
using namespace std;

//come back again for this tutorial
// https://leetcode.com/problems/reverse-pairs/solutions/127560/reverse-pairs ---multiple method  and god theory

class Solution {
    public:
        // merge sort
        int merge(vector<int>&nums,int s,int e,int mid){
            int cnt=0;
            int i=s;
            int j=mid+1;
            vector<int> temp;
            while(i<=mid ||  j<=e){
                if(i<= mid && j<=e && nums[i]<= nums[j]){
                    temp.push_back(nums[i++]);
                    
                }else{
                    // nums[i] > nums[j]
                    // all the elements from i to mid are greater than nums[j]
                    // cnt += (mid-i+1); //for tocount swaps
                    if(i<=mid && j<=e && nums[i] > 2*nums[j]){
                        cnt++; //+= (mid-i+1); //for tocount swaps
                    }
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            while(i<=mid){
                temp.push_back(nums[i]);
                i++;
            }
            return cnt;
        }
        int mergeSort(vector<int>& nums,int s,int e){
            if(s>=e){
                return 0;
            }

            int mid = s+ (e-s)/2;

            int left = mergeSort(nums,s,mid);
            int right =  mergeSort(nums,mid+1,e);

            return merge(nums,s,e,mid);

        }
        int reversePairs(vector<int>& nums) {
            return mergeSort(nums,0,nums.size()-1);
        }
    };