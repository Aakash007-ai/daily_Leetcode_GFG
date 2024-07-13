#include<bits/stdc++.h>
using namespace std;

//by default pq store as max heap max element at top in pq and also max element get pop out
//insertion and deletion o(log(n))
// also it store replicating elements as usual and does not decrement anything

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

     priority_queue<int> pq(arr.begin(),arr.end());
    //priority_queue<int, vector<int>, greater<int>> pq(arr.begin(),arr.end());

    while(!pq.empty()){
        cout<<pq.top();pq.pop();
    }
}