#include<bits/stdc++.h>
using namespace std;

//for loop if I then mp[i] then add with prev if V then mp[i]-mp[i-1] 
// IX = 10 -1  , IV = 5-1 ,  VII = 5+7  , if str[i]>str[i-1] then mp[str[i]]-mp[str[i-1]]  
class Solution {
    public:
    int romanToDecimal(string &str){
        unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int i=0,ans=0,n=str.size();
        while(i<n){
            if(i+1<n && mp[str[i+1]]>mp[str[i]]){
                ans+= mp[str[i+1]]-mp[str[i]];
                i+=2;
            }
            else{
                ans += mp[str[i]];
                i++;
            }
        }
        return ans;
        }
};
int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.romanToDecimal(s);
}
