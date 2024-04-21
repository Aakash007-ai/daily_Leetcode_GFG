#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
public:
int get(int index);
int length();
};

class Solution {
public:
    int solve(MountainArray &MountainArray,int s,int e){
        int mid=((e-s)/2 + s);
        while(s<e){
            mid=((e-s)/2 + s);
            int mid=MountainArray.get(mid);
            int left=MountainArray.get(mid-1);
            int right=MountainArray.get(mid+1);
            if(mid>left && right>mid) s=mid;
            else if(mid<left && mid>right) e=mid;
            else if(mid>left && mid>right) break;
        }
        return mid;
    }
    pair<bool,int> binarySearch(MountainArray &MountainArray,int s,int e,bool inc){
        

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //first find mountain index
        int s=0,n=mountainArr.length()-1;
        int e=n;
        int mountId=solve(mountainArr,s,e);
        if(mountId > 0 && mountId<n){
            //now binary search on both side to find target
            pair<bool,int> left=binarySearch(mountainArr,0,mountId,true);
            if(left.first) return left.second;
            left=binarySearch(mountainArr,mountId,e,false);
            if(left.first) return left.second;
        }
        return -1;
    }
};