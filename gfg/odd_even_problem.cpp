#include<bits/stdc++.h>
using namespace std;
// given a string s of lowercase characters determine whether x+y is odd or even
//x is count of  distinct characters that occupy even position and have even frequency
// so we must know the frequency of each character earlier
// then iterate over even position and take and we have to take a check whether we have considered that or not
// for that we need a visited array

// same for y at odd position
// so we have that frequency common
//but x and y visited must be different

// optimised approach
class Solution{
    public:
    string oddEven(string s){
        unordered_map<char,int> freq;
        for(auto it:s) freq[it]++;
        vector<int> x_visited(26,0),y_visited(26,0);
        int x=0,y=0;
        for(int i=1;i<=s.size();i++){
            if(i&1){
                //odd posiiton
                if(freq[s[i-1]]%2 && !y_visited[s[i-1]-'a']){
                    x++;y_visited[s[i-1]-'a']++;
                }
            }else{
                //even position
                if(freq[s[i-1]]%2==0 && x_visited[s[i-1]-'a'])
            }
        }
    }
};


// another approach
// class Solution {
//   public:
//     string oddEven(string s) {
//         // code here
//         int x=0; //count of distinct characters at even position
//         vector<int> x_count(26,0);
//         for(int i=2;i<=s.size();i+=2){
//             if(x_count[s[i-1]-'a']==0){
//                 x++;//increment count new distinct elemetn found at even position
//                 x_count[s[i-1]-'a']++;// mark that character as visited
//             }
//         }
//     }
// };