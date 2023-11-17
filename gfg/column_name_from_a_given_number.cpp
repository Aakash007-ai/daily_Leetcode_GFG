#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string colName (long long int n)
    {
        string ans;
        while(n)
        {
            n--;   // for 0- based indexing
            int rem = n % 26;
            ans += char('A' + rem);
            n = n / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    
    // string colName (long long int n){
    //     // your code here
    //     long long int i=1;
    //     long long col=26;
    //     string ans="";
    //     while(i<=n){
    //         if(n<=col){
    //             ans.push_back(char(n+65-1));
    //             n-=26;
    //         }
    //         else{
    //             ans.push_back('A');
    //             n-=26;
    //         }
    //     }
    //     return ans;
    // }
};

int main(){
    long long int n;
    cin>>n;
    Solution obj;
    cout<<obj.colName(n);
}