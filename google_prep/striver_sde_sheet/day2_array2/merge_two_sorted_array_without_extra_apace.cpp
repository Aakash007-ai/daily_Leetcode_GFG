#include<bits/stdc++.h>
using namespace std;

//first make alogo with sample use case
// 1,2,3,0,0,0
// 2,5,6
// 1,2,2,3,5,6 //firs m 2 came first

/*

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while(i!=-1 && j!=-1){
        if(nums2[j] >= nums1[i]){
            nums1[k--] = nums2[j--];
        }else {
            nums1[k--]= nums1[i--];
        }
    }

    while(j>=0){
        nums1[k--]=nums2[j--];
    }
        
    }
};