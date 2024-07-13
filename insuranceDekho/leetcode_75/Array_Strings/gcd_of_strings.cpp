#include<bits/stdc++.h>
using namespace std;
/*
    find x such that str1%x==0 str2%x==0
    x should be repeating in both str1 and str2
    so as str2 should be repeating
    so match str2 as substring in str1
*/

// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         //assuming str1 is big one
//         int n=str1.size();
//         int m=str2.size();

//         for(int i=0;i<n-m;i+=m){
//             if(str1.substr(i,m)!=str2){
//                 return "";
//             }
//         }
//         //we are confirm that str2 is repeating in str1
//         //now check whether str2 is divisible or not

//         // int i=0,j=1; //finding repetition as we find above
//         // while(j<m){
//         //     //check whether it is repeating or not 
//         //     if(str2[i]==str2[j]){
//         //         for(int k=0;k<m-j;k+=m){
//         //             if(str1.substr(i,m)!=str2){
//         //             return "";
//         //             }
//         //         }
//         //     }
//         // }

        
//         return "";
//     }
// };


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};


int main(){
    string x;
    cin>>x;
    string y;
    cin>>y;
    // cout<<"heello"<<endl;
    Solution obj;

    cout<<obj.gcdOfStrings(x,y);
}