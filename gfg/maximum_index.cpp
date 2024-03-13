#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxIndexDiff(int a[], int n) //so we got arr and n number of elements
    { 
        vector<int>v; //take a vector v
        v.push_back(n-1);//push last index
        cout<<"pushed last index in vector v i.e. "<<n-1<<"\n";
        for(int i=n-2;i>=0;i--){//start iterating elements from last
            if(a[i]>a[v.back()]){
                printf("pushing index %d as %d is greater than %d which is last pushed index of greater arr element\n",i,a[i],a[v.back()]);

                v.push_back(i);
            }
        }
        int ans=0;
        cout<<"starting loop from 0 to n-1="<<n-1<<endl;
        for(int i=0;i<n-1;i++){
            cout<<"for i = "<<i<<"while loop condition v.size()>0 && a[i]<=a[v.back()]"<<endl;
            while( v.size()>0 && a[i]<=a[v.back()]){

                ans=max(ans,v.back()-i);
                v.pop_back();
            }
        }
        return ans;
        
    }
};


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Solution obj;
    cout<<obj.maxIndexDiff(arr,n);

}