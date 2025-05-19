#include<bits/stdc++.h>
using namespace std;

//e.g. 
//1          1
//2        1   1 
//3      1   2   1  
//4    1   3   3   1
//5  1   4   6   4   1


//for i=3, j=2
// arr[2][1]+arr[2][2]
// i-1 , j-1   i-1 j

//go through flow , if 1 based indexing , don't get confused use extra-1 while accessing index value, be relax
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;// numRows is 1 based indexing
        for(int i=1;i<=numRows;i++){//2
            vector<int> temp;
            for(int j=1;j<=i;j++){//i=3
                if(j==1){
                    temp.push_back(1);
                }else if(i>1 && j==i){
                    temp.push_back(1);
                }else{
                    temp.push_back(ans[i-2][j-2]+ans[i-2][j-1]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
    // 0 based indexing
    //    vector<vector<int> > generate(int numRows) {
    //     vector<vector<int>> r(numRows);
    //     for (int i = 0; i < numRows; i++) {
    //         r[i].resize(i + 1);
    //         r[i][0] = r[i][i] = 1;
    //         for (int j = 1; j < i; j++)
    //             r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    //     }
    //     return r;
    // }

int main(){
    int n;
    cin>>n;
    Solution obj;
    vector<vector<int>> ans = obj.generate(n);

}