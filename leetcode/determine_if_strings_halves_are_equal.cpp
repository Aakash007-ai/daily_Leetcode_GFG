#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        //2 unordered map
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        //n= 6 thn  6/2 = 3  0,1,2    3,4,5
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int leftCount=0,rightCount=0;
        int half=s.size()/2;
        for(int i=0;i<s.size()/2;i++){
            if(st.find(s[i]) != st.end()) leftCount++;
            if(st.find(s[i+ half]) != st.end()) rightCount++;
        }

        return leftCount==rightCount;
    }
};