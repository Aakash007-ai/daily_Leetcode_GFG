#include<bits/stdc++.h>
using namespace std;

class Solution {//try again
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     if(beginWord == endWord) return 1;
    //     int level=0;
    //     unordered_set<string> list(wordList.begin(),wordList.end());//wordlist to search word
    //     queue<string> q;//queue for iteration
    //     q.push(beginWord);//start queue with source
    //     unordered_set<string> vis; // so that we will not go for further loop
    //     vis.insert(beginWord);// it is more fast to  , if it has been or it is in queue , mark it as visited

    //     while(!q.empty()){
    //         int n= q.size();
    //         level++;
    //         while(n--){
    //             string orgStr = q.front(); q.pop();
    //             if(orgStr==endWord) break;
    //             for(int i=0;i<orgStr.size();i++){
    //                 //here a nested loop with iterating and changin 26 cahracter at on elpace
    //                 string temp(orgStr.begin(),orgStr.end());
    //                 for(int j=97;j<123;j++){
    //                     temp[i]=(char)j;
    //                     //now we have a new characterstring check if it is original(don't care already in vis, check it in list)
    //                     if(vis.find(temp) == vis.end() && list.find(temp) != list.end()){
    //                         //fresh element is in list   
    //                         q.push(temp);
    //                         vis.insert(temp);
    //                         list.erase(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return level;
    // }
};


int main(){
 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    Solution obj;
 
    int ans = obj.ladderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
}