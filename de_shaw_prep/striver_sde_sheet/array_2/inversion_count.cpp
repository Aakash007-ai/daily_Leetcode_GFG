#include <bits/stdc++.h> 
using namespace std;

long long int a=0;

long long int merge(long long *arr, int s,int mid,int e ){
    int left=mid-s+1;
    int right=e-mid;
    int *first=new int[left];
    int *second = new int [right];
    int k=s;
    for(int i=0;i<left;i++){
        first[i]=arr[k++];
    }
    for(int i=0;i<right;i++){
        second[i]=arr[k++];
    }
    int i=0,j=0,cnt=0;
    k=s;
    while(i<left && j<right){
    //this is added from merge sort
        if(second[j]<first[i] )cnt+=left-i;
        if( first[i] < second[j] ){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=second[j++];
        }
    }

    while(i<left){
        arr[k++]=first[i++];
    }

    while(i<left){
        arr[k++]=second[j++];
    }
    delete []first;
    delete []second;
    return cnt;
}

long long int mergesort(long long  *arr, int s,int e ){
    if(s>=e){
        return 0;
    }
    long long int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    a+=merge(arr,s,mid,e);
    return a;
}

long long getInversions(long long *arr, int n){
    long long int ans=mergesort(arr,0,n-1);
    return ans;
}




// class Solution {
// public:
//     long long merge(vector<long long> &nums,long long s,long long mid,long long e){
//         //we have s and e different all are inclusive
//         //so creating a new vector then 
//         vector<long long> temp;
//         long long i=0;
//         long long x=s,y=mid+1;
//         //assume two pointer x and y pointing to 2 sorted array  and we just have to merge them
//         //so there will be some edge cases, either we traverse first vector complete then we just have to copy other elements
//         //assume 2 cases [a,b] [c,d] ans can be abcd , cdab ,acbd ,cadb
//     long long count= 0;
//     while (x <= mid || y <= e) {//both are inclusive
//             if(y <= e && x<=mid && nums[y] <= nums[x]){ //nums[y] is smaller put that in vector
//                 temp.push_back(nums[y++]);
//                 cout += (mid - x);
//             }else{
//                 if(x>mid){
//                     temp.push_back(nums[y++]);
//                 }else{
//                     temp.push_back(nums[x++]);
//                 }
          
//             }
//         }
//         long long k=0;
//         for(long long i=s;i<=e;i++){
//             //push in nums
//             nums[i]=temp[k];
//     }
//     return count;
        
//     }

//     long long mergeSort(vector<long long> &nums,long long s,long long e){
//         //divide and merge
//         if(s>= e) return 0;
        

//         long long mid=s + (e-s)/2;
//         long long ans=mergeSort(nums,s,mid);
//         ans+=mergeSort(nums,mid+1,e);
//         ans += merge(nums, s, mid, e);
//         return ans;
//     }

//     long long sortArray(vector<long long>& nums) {
//         return mergeSort(nums,0,nums.size()-1);
        
//     }
// };

// long long getInversions(long long *arr, long long n){
//     // Write your code here.
//     long long n; cin >> n;
//     vector < long long > arr; (n);
//     for (long long i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//         // vector<int> arr = {5,2,3,1};
//     Solution obj;
//     // vector < int > ans=obj.sortArray(arr);
//     cout << obj.sortArray(arr);
// }