#include<bits/stdc++.h>
using namespace std;

//brute force care a map and store element in map and then find double,
// but here something given a range 1-n inclusive means element lie between them 

/*
    so we can take extra space o(n) and time complexity o(n)
    for(loop) and a map or array of vector 
    here max time complexity to allowed is nlog(n);

    so we can think of having time complexity nlogn so we can devise a method of constant time complexity 
    so we can have n/2 loop and inside that loop o(n) loop
    or 
    o(n) loop and inside that logn

    so assuming a number line 1 to 7
    we take low and end ansd use binary search (logn)
    search for middle , and for middle take a count over ele:array and check if count
    if no. of elements are greater than count means we have more no. of elements 
*/
class Solution {
public:
    // this method work when only 1 element is double , if all element are same then what?
    // int findDuplicate(vector<int>& nums) {
    //     int nPlus = nums.size();
    //     int n=nPlus-1;
    //     int ans= nums[0];
    //     for(int i=1;i<nPlus;i++){
    //         ans^=i;
    //         ans^=nums[i];
    //     }
    //     return ans;
    // }
};