#include<bits/stdc++.h>
using namespace std;
//don't over comlpex things first try to solve via bruteforce then optimized

//reverse vowels 
// using 2 pointer represting starting and ending vowles
class Solution {
public:
    bool isVowels(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(isVowels(s[i])){
                //find jth vowel
                while(i<j && !isVowels(s[j])){
                    j--;
                }
                if(i<j && isVowels(s[j])) swap(s[i++],s[j--]);
            }
        }
        return s;
    }
};

