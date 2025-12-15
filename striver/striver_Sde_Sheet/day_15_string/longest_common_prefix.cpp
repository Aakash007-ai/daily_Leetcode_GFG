#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref =  strs[0];

        if(pref.size() == 0) return "";
        int prefLen = pref.size();

        for(int i=1;i<strs.size();i++){
            while(prefLen > strs[i].size() || pref.substr(0,prefLen) != strs[i].substr(0,prefLen)){
                if(prefLen == 0) return "";
                prefLen--;
            }
        }

        return pref.substr(0,prefLen);
    }
};