#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    long long mod = 1e9+7;
    vector<long long> nthRowOfPascalTriangle(int n) {
        if(n==1) return {1};
        if(n==2) return {1,1};
        vector<vector<long long>> v(n);
        v.push_back({1});
        v.push_back({1,1});
        for(int i=2;i<n;i++){
            v.push_back({});
            for(int j=0;j<=i;j++){
                if(j==0){
                    v[i].push_back(v[i-1][0]);
                    continue;
                }else if(j==i){
                    v[i].push_back(v[i-1][j-1]);
                    continue;
                }
                else{
                    v[i].push_back(v[i-1][j]+v[i-1][j-1]);
                }
            }
        }
        return v[n-1];
    }
};










// vector<long long> nthRowOfPascalTriangle(int n) {
//         // code here
//         int MOD = 1e9 + 7;
//         vector<long long> row(n, 1); 
        
//         for (int i = 1; i < n; ++i) {
//             for (int j = i - 1; j > 0; --j) {
//                 row[j] = (row[j] + row[j - 1]) % MOD; }
//         }return row;
//     }


    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long> prev;
        int mod = 1e9+7;
        
        for(int i=0; i<n; i++) {
            vector<long long> curr(i+1, 1);
            for(int j=1; j<i; j++) {
                curr[j] = (prev[j-1]+prev[j])%mod;
            }
            
            prev = curr;
        }
        
        return prev;
    }