#include<bits/stdc++.h>
using namespace std;

//substring with exactly k distinct characters
// sliding window


//aba k=2
// ab ,ba ,aba  there are 3 substring

// abaaca k=1
// a , b , a, aa ,a,  c,a 6
class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
        unordered_map<char,int> mp;
        int i=0,j=0,n=s.length();
        int ans=0;
        while(j<n){
            mp[j++];//put 1 character and increase j
            while(j-i<k){//making window, 
            //we can't do nothing until we make window of atleast k size so pushing elements
            mp[j++];

            }
            if(mp.size()==k){
                ans++; continue;
            }
            while(j-i>k)
        }
        //increase i till we get j-i<k and count left substring
    }
};

