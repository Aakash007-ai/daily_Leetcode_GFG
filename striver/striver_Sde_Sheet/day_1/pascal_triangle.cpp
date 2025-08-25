#include<bits/stdc++.h>
using namespace std;


/**
 * pascal traingle
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 */

 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows > 0){
            ans.push_back({1});
        }
        if(numRows > 1){
            ans.push_back({1,1});
        }

        for(int i=2 ; i< numRows; i++){
            vector<int> prev = ans[i-1];
            vector<int> temp = {};
            for(int j=0 ; j<=i; j++){
                if(j==0 || j == i){
                    temp.push_back(1);
                }else{
                    temp.push_back(prev[j-1] + prev[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};