#include<bits/stdc++.h>
using namespace std;



class Solution {
    public:
    // string countAndSay(int n){ // looks ok but have a logical bug
    //     if(n==1) return "1";

    //     string prev = countAndSay(n-1);

    //     int cnt = 1;
    //     char say = prev[0];

    //     string ans = "";

    //     int sz=prev.size();
    //     for(int i=1;i<sz;i++){
    //         if(say!=prev[i]){
    //             cnt = 1;
    //             say = prev[i];
    //         }else{
    //             ans.pop_back();
    //             ans.pop_back();
    //             cnt++;
    //         }

    //         ans.push_back(cnt+'0');
    //         ans.push_back(say);
    //     }

    //     return ans;
    // }

    string countAndSay(int n){
    if(n == 1) return "1";
    
    string prev = countAndSay(n-1);
    
    int cnt = 1;
    char say = prev[0];
    string ans = "";
    
    int sz = prev.size();
    for(int i = 1; i < sz; i++){
        if(say != prev[i]){
            // Append count and digit for previous group
            ans.push_back(cnt + '0');  // Convert int to char
            ans.push_back(say);
            
            // Start new group
            cnt = 1;
            say = prev[i];
        } else {
            cnt++;
        }
    }
    
    // Don't forget the last group
    ans.push_back(cnt + '0');
    ans.push_back(say);
    
    return ans;
}
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.countAndSay(n);
}