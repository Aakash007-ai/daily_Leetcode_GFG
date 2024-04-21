#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();//we always have one candy
        int extraCandy=0;
        for(int i=0;i<n;i++){
            if(i==0 && extraCandy>i && ratings[i]>ratings[i+1]){
                extraCandy++;
                continue;
            }
            else if(i==n-1 && i>0 && ratings[i]>ratings[i-1]){
                extraCandy++;
                continue;
            } 
        }
    }
};