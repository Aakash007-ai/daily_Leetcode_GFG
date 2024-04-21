#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //nums1 has more size
        if(nums2.size()==0) return ;

        if(nums1[m-n-1]<nums2[0]){
            //just push elemenets
            
        }

        int i=0,j=0;
        while(i<nums1.size() && j< nums2.size()){
            //so i refers to ith element of nums1 and j refers to jth element of nums2
            if(nums1[i]>nums2[j]){
                //push nums2[j] in nums1[i] position as nums2[j]<nums[i]
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
            }else{
                i++;
            }
        }

        if(j!=nums2.size()){
            //just push j to m-1 elements at last of 
            
        }
    }
};