#include<bits/stdc++.h>
using namespace std;

//use only constant extra space
// 1 3 4 2 2
/*  so iterating over array
    for i=0; 
    if arr[i] == i+1;
        continue;
    if(arr[arr[i]]
    )


*/

/*
    todo :- sort an array given
    iterate over array and swap
    for(int i=0;i<n;i++){
        if(arr[i]=i+1) //then everything is ok element is at its right poisition
    }
*/


//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         int ans;
//         for(int i=0;i<nums.size();i++){
//             if(mp.find(nums[i]) != mp.end()){
//                 ans= nums[i];break;
//             }
//             mp[nums[i]]++;
//         }
//         return ans;

// int findDuplicate(vector<int>& nums) {
//     unordered_set<int> st;
//     int ans;
//     for(int i=0;i<nums.size();i++){
//         if(st.find(nums[i]) != st.end()){
//             ans= nums[i];break;
//         }
//         st.insert(nums[i]);
//     }
//     return ans;
// }








class Solution {
public:
        int findDuplicate(vector<int>& nums) {
            int slow=0,high=0;
            do{
                slow=nums[slow];
                high=nums[nums[high]];
            }
            while(slow !=high);

            int slow2=0;
            do{
                slow2=nums[slow2];
                slow=nums[slow];

            }while(slow!=slow2);
            return slow;
    }
};




// class Solution {
// public:
//         int findDuplicate(vector<int>& nums) {
//         int low = 1, high = nums.size() - 1, cnt;
        
//         while(low <=  high)
//         {
//             int mid = low + (high - low) / 2;
//             cnt = 0;
//             // cnt number less than equal to mid
//             for(int n : nums)
//             {
//                 if(n <= mid)
//                     ++cnt;
//             }
//             // binary search on left
//             if(cnt <= mid)
//                 low = mid + 1;
//             else
//             // binary search on right
//                 high = mid - 1;
            
//         }
//         return low;
//     }
// };



int main(){
    int n;cin>>n;
    vector<int> arr(n+1);
    for(int i=0;i<=n;i++){
        int x;cin>>x;
        arr[i]=x;
    }
    Solution obj;

    cout<<"Duplicate number is : "<<obj.findDuplicate(arr);

}







// class Solution {
// public:
//         int findDuplicate(vector<int>& nums) {
//         int low = 1, high = nums.size() - 1, cnt;
        
//         while(low <=  high)
//         {
//             int mid = low + (high - low) / 2;
//             cnt = 0;
//             // cnt number less than equal to mid
//             for(int n : nums)
//             {
//                 if(n <= mid)
//                     ++cnt;
//             }
//             // binary search on left
//             if(cnt <= mid)
//                 low = mid + 1;
//             else
//             // binary search on right
//                 high = mid - 1;
            
//         }
//         return low;
//     }
// };