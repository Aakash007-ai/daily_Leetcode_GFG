#include<bits/stdc++.h>
using namespace std;
//ASCII value
/*
    A   65  Z   90
    a   97  z   122
    a = A+32
*/

// class Solution {
// public://given all chars in c and t are lower case
//     char findTheDifference(string s, string t) {//gives runtime error
//         if(s.length() ==0) return t[0];
//         vector<int> cs(25,-1);
//         vector<int> ct(25,-1);
//         for(char c : s ) cs[c-97]++;
//         for(char c:t) ct[c-97]++;
//         char ans;
//         for(int i=0;i<25;i++){
//             if(cs[i]!=ct[i]){ ans=char(i+97); break;}
//         }
//         return ans;
//     }
// };



class Solution {
public://given all chars in c and t are lower case
    char findTheDifference(string s, string t) 
    {
      for(int i=0;i<s.size();i++)
		t[i+1]+=t[i]-s[i]; //Passing the diff: (t[i]-s[i]) to t[i+1]
      return t[t.size()-1]; //The diff will be carried over to the last element eventually
    }
};