#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        // Your code here
        for(int i=1;i<n;i+=2){
            swap(arr[i],arr[i-1]);
        }
    }
};


int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    Solution obj;
    obj.convertToWave(n,v);
}