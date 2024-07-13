#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution{
	public:
	int perfectSum(int arr[], int n, int sum){
        if(sum==0) return 1;// we got a sum
        if(n==0) return 0;
        if(sum>= arr[n-1]){
            return perfectSum(arr,n-1, sum -arr[n-1]) + perfectSum(arr,n-1,sum);
        }
        return perfectSum(arr,n-1,sum);
	}
};

int main(){
    int n,sum;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;
    Solution obj;
    cout<<obj.perfectSum(arr,n,sum);
}