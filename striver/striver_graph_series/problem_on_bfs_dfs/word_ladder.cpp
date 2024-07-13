#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //end case if endWord is not present in wordlist
        unordered_set<string> list(wordList.begin(),wordList.end());
        if(list.find(endWord)==list.end()) return 0;//endword is not present in list

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                auto node=q.front();q.pop();
                string currString=node.first;
                for(int i=0;i<currString.length();i++){
                    string tempString = currString;
                    for(int j=0;j<26;j++){
                        tempString[i]=char('a'+j);
                        if(tempString==endWord){ //we got our answer new string is present in our list
                            return node.second+1;
                        }
                        if(tempString!=currString && list.find(tempString)!=list.end()){
                            //new string formed and present in wordList
                            q.push({tempString,node.second+1});
                            list.erase(tempString);
                        }
                    }
                }
            }
        }
        return 0;
    }
};