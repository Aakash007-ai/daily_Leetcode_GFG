#include<bits/stdc++.h>
using namespace std;


class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){
	    //longest subarray sum divisible by k
        // arr[i]+arr[i+1]... % k ==0
	}
};

//brute force o(n**2)
// for(int i=0;i<n;i++){
//      for(int j=i;j<n;j++){
//         sum+=arr[i]
//          if(sum%k==0) mx=max(mx,j-i);
//}}







// int longSubarrWthSumDivByK(int arr[], int n, int k)
//     {
//         unordered_map<int,int> mp;
//         int maxi = INT_MIN;
//         int sum = 0;
//         for(int i = 0;i<n;i++){
//            sum += arr[i];
//            arr[i] = sum;
//            if(sum == 0)  maxi = max(maxi,i+1);
//            if(sum%k == 0) maxi = max(maxi,i+1);
           
//         }
//         for(int i = 0;i<n;i++){
//             arr[i] = arr[i]%k;
//             if(arr[i] < 0) arr[i] = arr[i] + k;
//             }
//         for(int i = 0;i<n;i++){
//              if(mp[arr[i]] >=1){
//                  maxi = max(maxi,i+1-mp[arr[i]]);
//              }
//              else mp[arr[i]] = i+1;
//         }
        
//         if(maxi == INT_MIN) return 0;
//         return maxi;
//     }