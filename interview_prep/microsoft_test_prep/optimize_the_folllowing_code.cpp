// https://leetcode.com/discuss/interview-question/1915190/Microsoft-or-OA-or-Redmond-WA-or-Get-Maximum-Distance-of-Same-Elements-in-an-Array

#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;



int solution(vector<int>& arr) {
    int result = 0;
    int arr_len = arr.size();
    for (int i = 0; i < arr_len; i++) {
        for (int j = 0; j < arr_len; j++) {
            if (arr[i] == arr[j]) {
                result = max(result, abs(i - j));
            }
        }
    }
    return result;
}


int solution1(vector<int> & arr){
    // if there is duplicte elements in array then find the longest separated duplicate eleements
    //so , if we iterate over array and store iterated elements with their index
    // next time we encounter duplicates we can find and get difference

    //for this we store the iterated element with their first index
    int ans=INT_MIN;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        if(mp.find(arr[i]) != mp.end()){
            ans=max(ans,i-mp[i]);
        }else{
            mp[arr[i]]=i;
        }
    }
    return ans;
}