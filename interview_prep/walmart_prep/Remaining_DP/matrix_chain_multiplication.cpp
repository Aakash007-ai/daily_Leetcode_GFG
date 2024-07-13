#include<bits/stdc++.h>
using namespace std;

//arr = [ 10,30,40,20,5]

//assume a input arr = [A,B,C,D]
//we have array a*b b*c and c*d
// 

//recursion
int solve(vector<int> arr,int i,int j) {
    if(i>=j) return 0;
    int ans=INT_MAX;
    for(int k=i;k<=i-1;i++){
        int temp = solve(arr, i, k)+ solve(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        ans =min(ans,temp);
    }
}

//memoization
int static t[101][101];//only i and j are changing so we make matrix of that

int solve(vector<int> arr,int i,int j) {//i and j is changing
    if(t[i][j]!= -1) return t[i][j];
    if(i>=j) return 0;
    int ans=INT_MAX;
    for(int k=i;k<=i-1;i++){
        int temp = solve(arr, i, k)+ solve(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
        ans =min(ans,temp);
    }
}


// int main(){
//     memset(t,-1,sizeof(t))//memset fill default value
// }