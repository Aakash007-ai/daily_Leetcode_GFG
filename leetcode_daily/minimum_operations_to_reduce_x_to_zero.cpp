#include<bits/stdc++.h>
using namespace std;
//contribute to a test case 
//test case 1 , where sum of elements is smaller than x but there are too many elements in it

//   int solve(vector<int> &nums,int i,int j,int x){
//         if(i>j && x) return INT_MAX;
//         if(x==0) return 0;
//         int left=INT_MAX;
//         if(x>=nums[i]){
//             left=solve(nums,i+1,j,x-nums[i]);
//         }
//         int right=INT_MAX;
//         if(x>=nums[j]){
//             right=solve(nums,i,j-1,x-nums[j]);
//         }
//         if(left == INT_MAX && right ==INT_MAX) return INT_MAX;
//         return 1+min(left,right); 
//     }
//     int minOperations(vector<int>& nums, int x) {
//         //printf("minOperation called\n");
//         //accumate sum of all elements if it is less than x return -1 (removed 1 case)
//         int ans = solve(nums,0,nums.size()-1,x);
//         if(ans==INT_MAX) return -1;
//         return ans;
//     }


class Solution {
public:
    int solve(vector<int> &nums,int i,int j,int x){
        //condition when j>i we have 2 cases either x become 0 in last step or not
        if(i>j && x) return INT_MAX;

        if(x==0) return 0;
        int left=INT_MAX;
        if(x>=nums[i]){
            left=solve(nums,i+1,j,x-nums[i]);
            printf("For x= %d, left is %d\n",left);
        }
        int right=INT_MAX;
        if(x>=nums[j]){
            right=solve(nums,i,j-1,x-nums[j]);
            printf("For x= %d, right is %d\n",right);
        }

        if(left == INT_MAX && right ==INT_MAX) return INT_MAX;
        
        return 1+min(left,right); 

    }
    int minOperations(vector<int>& nums, int x) {
        //printf("minOperation called\n");
        //accumate sum of all elements if it is less than x return -1 (removed 1 case)
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(x)));
        int ans = solve(nums,0,nums.size()-1,x);
        //printf("ans is %d\n",ans);
        if(dp[0][][x]==INT_MAX) return -1;
        return ans;
    }
};


int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[i]=x;
    }
    int x;
    cin>>x;
    Solution obj;
    cout<<obj.minOperations(v,x);
}



//either by dp  we have option to choose

/*  //3 2 20 1 1 3
    //0 1 2  3 4 5
    by recurion, choose i=0 and j=size of nums-1
    if(i>j) return -1;
    if(x==0) return  i(2)  + nums-j (6-2)
*/