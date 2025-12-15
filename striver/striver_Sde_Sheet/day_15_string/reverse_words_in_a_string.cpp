#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            string temp = "";
            while(i<n && s[i]!=' '){
                temp.push_back(s[i++]);
            }
            if(temp.size()>0) st.push(temp);
        }

        string ans = "";
        while(st.size()>1){
            ans += st.top();st.pop();
            ans.push_back(' ');
        }
        ans += st.top();
        return ans;
    }
};