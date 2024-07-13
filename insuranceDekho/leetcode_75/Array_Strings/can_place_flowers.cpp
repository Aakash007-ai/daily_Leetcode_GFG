#include<bits/stdc++.h>
using namespace std;

//don't overcomplicate easy question


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //first find zeroes in between 1 and put flowers there
        for(int i=0;i<n;i++){
            if(flowerbed[i]==1){
                //count next zero with variable i
                int j=i;
                int zero=0;
                while(j<n && !flowerbed[j++]){    
                    //perform claculations
                    zero++;
                    //find ans
                    //1 0 0 0 1 ans is 1
                    //1 0 0 0 0 1 
                }
            }
        }
        
    }
};
