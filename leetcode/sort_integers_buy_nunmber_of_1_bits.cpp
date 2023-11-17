#include<bits/stdc++.h>
using namespace std;

//number of set bits in number also calle
//to count hamming weight there is also a builtin function in c++ __builtin_popcount()

class Solution {
public:
    static bool compare(int a,int b){
        if(__builtin_popcount(a) == __builtin_popcount(b)){
            return a<b;
        }
        return __builtin_popcount(a) < __builtin_popcount(b);
    } 
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;   
    }
};