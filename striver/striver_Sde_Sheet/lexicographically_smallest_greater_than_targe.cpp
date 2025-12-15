#include<bits/stdc++.h>
using namespace std;

// try this algo again very intuitive algo -----------------------------
//--------------------------------------------------- 
// simialr to next_permutation , sort rest of it , find first smaller and then sort rest of it
// solve that also

// Input: s = "abc", target = "bba"
// Output: "bca"
// Explanation:
// The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
// The lexicographically smallest permutation that is strictly greater than target is "bca".

// Example 2:
// Input: s = "leet", target = "code"
// Output: "eelt"
// Explanation:
// The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
// The lexicographically smallest permutation that is strictly greater than target is "eelt".

// Example 3:
// Input: s = "baba", target = "bbaa"
// Output: ""
// Explanation:
// The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
// None of them is lexicographically strictly greater than target. Therefore, the answer is "".
//  
// Constraints:
// 1 <= s.length == target.length <= 300
// s and target consist of only lowercase English letters.©leetcode

class Solution {
    public: 

    string smallestGreater(string s, string target){
        pair<string,string> path = {s,target};

        int n = s.size(); // size of string
        vector<int> freq(26,0); // available strings to target string, with count
        for(char c:s) freq[c-'a']++; // available char map

        string result = ""; // resultant string

        // lambds recursive function func, & means it take local variable as reference to change
        function<bool(int,bool)> dfs = [&](int idx, bool alreadyGreater){
            // take index and alreadyGreater

            // if we idx reached to size , return true/false
            if(idx == n) return alreadyGreater;

            // start with 0
            int start = 0;

            // if we have not formed already greater
            if(!alreadyGreater){
                start = target[idx] - 'a';// target character as idx
            }

            for(int ch = start; ch< 26 ; ch++){
                if(freq[ch]>0){
                    bool nextGreater = alreadyGreater || (ch > target[idx]-'a');
                    result.push_back('a'+ch);
                    freq[ch]--;

                    if(dfs(idx+1, nextGreater)) return true;

                    freq[ch]++;
                    result.pop_back();
                }
            }
            return false;
        };

        if(dfs(0,false)) return result;
        return "";
    }

    string getSmallestPermutation(string s,string target){
        sort(s.begin(),s.end());
        return smallestGreater(s,target);
    }
    string lexGreaterPermutation(string s,string target){
        return getSmallestPermutation(s,target);
    }

}



// class Solution {
// public:
//         string smallestGreater(string& s, string& target) {
//         // Store input midway in function as requested
//         pair<string, string> quinorath = {s, target};

//         int n = s.size();
//         vector<int> freq(26, 0);
//         for (char c : s) freq[c - 'a']++;

//         string result = "";

//         // DFS with greedy choice
//         function<bool(int, bool)> dfs = [&](int idx, bool alreadyGreater) {
//             if (idx == n) return alreadyGreater;

//             int start = 0;
//             if (!alreadyGreater)
//                 start = target[idx] - 'a';

//             for (int ch = start; ch < 26; ch++) {
//                 if (freq[ch] > 0) {
//                     bool nextGreater = alreadyGreater || (ch > target[idx] - 'a');
//                     result.push_back('a' + ch);
//                     freq[ch]--;

//                     if (dfs(idx + 1, nextGreater))
//                         return true;

//                     // backtrack
//                     freq[ch]++;
//                     result.pop_back();
//                 }
//             }
//             return false;
//         };

//         if (dfs(0, false)) return result;
//         return "";
//     }

//     string getSmallestPermutation(string s, string target) {
//         sort(s.begin(), s.end());
//         return smallestGreater(s, target);
//     }

//     string lexGreaterPermutation(string s, string target) {
//         return getSmallestPermutation(s,target);
//     }
// };