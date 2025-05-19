#include<bits/stdc++.h>
using namespace std;



// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than n / 2 times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2] 2,3
// Output: 2


//map<int,int> mp;
//mp[ele]++;


// n/
// for (it:map){}
// if it.value>n/2
// 2 -> 1
// 2-> 2; mp 
// mp 2->2 , 1->1
// mp 2-> 2, 1->2
// mp 2->2, 1->3
// mp 


//n =9 , 5
//finally
// mp 2-> 5 , 1-> 3 

int mostOccur(vector<int> arr){
    int n= arr.size()/2;
    unordered_map<int,int> mp;
    for(auto it:arr){
        mp[it]++;

        if(mp[it]>n/2) return it;
    }
}



int main(){
    int n = 9;
    vector<int> arr(9);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }

    cout<<"ans is "<<mostOccur(arr);
}






// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.


// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]

// Example 2:

// Input: numbers = [2,3,4], target = 6
// Output: [1,3]

// Example 3:

// Input: numbers = [-1,0], target = -1
// Output: [1,2]

// 2,7,11,15
// i=0 and  j=n-1;
// arr[i]+arr[j]=17

//target is always there

// vector<int> twoSum(vector<int> arr, int target){
//     //array is sorted
//     int n= arr.size();
//     int i=0;
//     int j= n-1;
//     vector<int> ans;
//     while(i<=j){
//         int tempSum = arr[i]+arr[j];
//         if(tempSum == target){
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }else if(tempSum > target){
//             j--;
//         }else {
//             i++;
//         }
//     }
// }

// int main(){
//     vector<int> samp;
//     samp.push_back(2);
//     samp.push_back(7);
//     samp.push_back(11);
//     samp.push_back(15);

//     int target = 9;

//     vector<int> ans = twoSum(samp,target);
//     cout<<" ans is "<<ans[0] <<" "<< ans[1];
// }