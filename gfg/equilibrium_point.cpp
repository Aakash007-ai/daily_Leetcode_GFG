#include<bits/stdc++.h>
using namespace std;

//first brute force accumulate sum and then iterate
//next we can use binary search with preficx sum
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        long long netSum=0; 
        accumulate(a,a+n,netSum);
        printf("netSum is %d :-",netSum);
        long long sum=netSum;
        netSum/=2;
        for(int i=0;i<n;i++){
            sum-=a[i];
            if(sum==netSum) return i+1;
        }
        return -1;
        // Your code here
    }

};

int main(){
    int n;cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printf("first array index value %d",arr[0]);
    Solution obj;
    cout<<obj.equilibriumPoint(arr,n)<<endl;;

}