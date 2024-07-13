#include<bits/stdc++.h>
using namespace std;



// Input: number = "123", digit = "3"
// Output: "12"
// Explanation: There is only one '3' in "123". After removing '3', the result is "12".
//digit occur at least 1 times


//so which digit to remove to get maixmum

// 6396
//which one to remove 
// 396 and 639 removing last is beneficial

// 1291
// 291 or 129 removing front is beneficaial


//brute force is ok with that

    string removeDigit(string number, char digit) {
        // IT WILL RETURN THE SIZE OF THE NUMBER STRING
        int n=number.size();
        // IT WILL STORE THE ANSWER AND RETURN THE ans STRING
        string ans = "";
        for(int i=0;i<n;i++){   
            // CHECK IF THE ith DIGIT IS EQUAL TO THE digit
            if(number[i]==digit){   
            // IT WILL RETURN THE SUBSTR BEFORE AND AFTER THE ith INDEX
            string s = number.substr(0,i) + number.substr(i+1);
            // ans WILL STORE THE MAX OF ans AND s 
            ans = max(ans,s);
            }
        }
        return ans;
    };


class Solution {
public:
    string removeDigit(string number, char digit) {}
        // convert number string to actual number to find max
        // how to remove a particular char from number

        //first find that occurences and store in map
    //     vector<int> index;
    //     for(int i=0;i<number.size();i++){
    //         if(number[i]==digit) index.push_back(i);
    //     }

    //     int ans=INT_MIN;
    //     string resString="";
    //     if(index.size()==1){
    //         // remove the single and return string
    //         auto it= number.find(digit);
    //         number.erase(number.begin()+index[0]);
    //         return number;
    //     }
    //     else{
    //         //try to iterate and find max string
    //         for(auto it:index){
    //             string temp(number.begin(),number.end());
    //             temp.erase(temp.begin()+it);
    //             if(stoi(temp)>ans){
    //                 ans=stoi(temp);
    //                 resString=temp;
    //             }
    //         }
    //     }
    //     return resString;
    // }
};