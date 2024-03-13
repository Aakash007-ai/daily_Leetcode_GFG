#include<bits/stdc++.h>
using namespace std;

//reduce character which has max number of characters as a^2 +b^2 +c^2
// reduce the a,b,c which is greates first so priority queue as character,

//brute force
//store frequency in priority queue and decrease till we get k=0
//store frequency in map and then priority queue

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++; //it mp[it] will store in map and then increment start from 0
        }
        priority_queue<int> pq; //we just need numbers
        for(auto it :mp){
            pq.push(it.second);
        }
        while(k-- && !pq.empty()){//check k and decrement it then check priority queue right to left
            int ele=pq.top();pq.pop(); //remove top element 
            ele-=1;
            pq.push(ele);
        }

        //now find value
        int ans=0;
        while(!pq.empty()){
            int ele=pq.top();pq.pop();
            //no do its pow 2
            ans += (ele*ele);
        }
        return ans;
    }
};

int main(){
    string s;
    int k;
    cin>>s>>k;
    Solution obj;
    cout<<obj.minValue(s,k);
}