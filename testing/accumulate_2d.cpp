#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v= {{0,0,0,0},{0,1,1,0},{1,0,1,0},{0,1,0,0}};
    int sum=0;
    int ans=accumulate(v[1].begin(),v[1].end(),sum);
    cout<<sum<<" "<<ans;

}