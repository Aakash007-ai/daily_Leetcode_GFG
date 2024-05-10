#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int rowCount=INT_MAX;int rowNum=0;
        int i=0;    
        for(auto it:a){
            int sum=0;
            sum=accumulate(it.begin(),it.end(),0);
            if(sum<rowCount){
                rowNum=i;
                rowCount=sum;
            }
            i++;
        }
        return rowNum;
    }
};