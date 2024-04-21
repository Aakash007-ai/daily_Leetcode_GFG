#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0'; //ascii of this is 0 

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                maxDigit = max(maxDigit, num[index]);//asci of 0 to 9 in string is from 48 to 57
            }
        }

        // If 'maxDigit' is NUL return an empty string, otherwise string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};
// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         char mx="";
//         for(int i=1;i<num.size()-1;i++){
//             int l=num[i-1];
//             int c=num[i];
//             int r=num[i+1];
//             if(l==c && c==r){
//                 mx = max(int(mx),int(l));
//                 if(mx==l){
//                     ans
//                 }
//             }
//         }
//     }
// };