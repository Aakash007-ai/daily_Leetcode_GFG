#include<bits/stdc++.h>
using namespace std;

//using take two pointer and iterate over them
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int f=-1,l=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                if(f==-1){
                    f=i;
                    l=i;
                }else{
                    l=i;
                }
            }
        }
        return {f,l};
        // code here
    }
};


int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution obj;
    vector<int> ans=obj.find(arr,n,x);
}