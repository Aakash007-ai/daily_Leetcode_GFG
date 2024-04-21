#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first < b.first){
        return true;
    }
    else if(a.second < b.second) return true;
    return false;
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // priority_queue<pair<int,int>> q;//no need of priority queue we can sort at last using custom sort comparator
        //but try this to get familar with priority_queue
        //11000  i=0 j=5 mid=i+j/2 => mid=2;
        //try nlogm
        vector<pair<int,int>> v;
        for(int i=0;i<mat.size();i++){
            int ones=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0) break;
                else ones++;
            }
            v.push_back(make_pair(ones,i));
            //v.push_back({ones,i});
        }
        //we have to sort by ascending order less ones and if ones are equal then next index ahould be less too
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it:v){
            if(k==0) break;
            k--;
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main(){
    int x,y;
    cin>>x>>y;
    cout<<"x is : "<<x<<"\ny is : "<<y;
    vector<vector<int>> mat(x,vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int x;cin>>x;
            mat[i][j]=x;
        }
    }
    for(auto it:mat){
        for(auto itr:it){
            cout<<itr<<" ";
        }
        cout<<"\n";
    }
    int  k;cin>>k;
    cout<<"k is : "<<k;
    Solution obj;
    vector<int> ans = obj.kWeakestRows(mat,k);
    cout<<"ans is : ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    
}