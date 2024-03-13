#include<bits/stdc++.h>
using namespace std;

//check problem largest number formed from an array GFG (one variant)

//always make sound while writing code code what you think and speak it to make code error free

//mak
//sort a vector of pairs

bool comp(pair<int,int> a,pair<int,int> b){
    //first index ascending then descending
    if(a.first<b.first) return true;
    else if( a.first == b.first) return b.second > a.second;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    sort(p.begin(),p.end(),comp);
    //sort(p.begin(),p.end());//sort vector of pairs  first by first then by second
    //cout<<p[0].first<<" "<<p[0].second;
    for(auto it:p){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    cout<<"\n";

}