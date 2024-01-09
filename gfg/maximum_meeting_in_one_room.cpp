#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
       vector<pair<int,int>>tmp; 
              for(int i=0;i<N;i++) {
            tmp.push_back(make_pair(F[i], i+1));
        }
            sort(tmp.begin(), tmp.end());
        
          vector<int>ans;
          ans.push_back(tmp[0].second);
          int last=tmp[0].first;
        
           for(int i=1;i<N;i++) {
              if(S[tmp[i].second-1]>last) {
                ans.push_back(tmp[i].second);
                last=tmp[i].first;
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;

}
    // int solve(int n,int prev_time,vector<pair<int,int>> &mt){//it will calculatye maximum no. of meetings
    //     if(n==0) return 0;
    //     if(prev_time>mt[n-1].second){//it measnif previous meeting start after curr ending this meeting can be attended
    //      return max(1+solve(n-1,mt[n-1].first,mt),solve(n-1,prev_time,mt));
    //     }
    //     return solve(n-1,prev_time,mt);
    // }
    // vector<int> maxMeetings(int n,vector<int> &S,vector<int> &F){
    //     vector<pair<int,int>> mt;
    //     for(int i=0;i<n;i++){
    //         mt.push_back({S[i],F[i]});
    //     }
    //     sort(mt.begin(),mt.end());
    //     vector<vector<int>> dp(n+1,vector<int> (mt.back().second+1));
    //     int count= solve(n,INT_MAX,mt);
    //     return {count};
    // }
};

int main(){
    int n;
    cin>>n;
    vector<int> start(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    vector<int> end(n);
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    Solution obj;
    vector<int> ans = obj.maxMeetings(n,start,end);
    for(auto it:ans){
        cout<<it<<" ";
    }
}