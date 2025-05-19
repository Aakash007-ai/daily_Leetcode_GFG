#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/4sum/solutions/3186501/best-c-3-solution-two-pointers-sorting-hash-table-brute-force-optimize
//n is 200 
// so 200*200*200 = 8*10^6 manageable time complexity
class Solution {
    public:
        //here order does not matter , just return numbers
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            //we have to return all combinations of 4 numbers
            sort(nums.begin(), nums.end());
            //if we fix 2 element and then find out 2 sum in sorted array 
            int n = nums.size();
            set<vector<int>> uniqAns;
            for(int i=0;i<n-3;i++){
                for(int j=i+1;j<n-2;j++){
                    int x=j+1, y=n-1;
                    long long sum = (long long)target-(long long)nums[i]-(long long)nums[j];
                    // cout<<nums[i]<<" "<<nums[j]<<" "<<sum<<endl;
                    while(x<y){
                        if(nums[x]+nums[y]==sum){
                            // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[x]<<" "<<nums[y]<<endl;
                            uniqAns.insert({nums[i], nums[j], nums[x], nums[y]});
                            x++;
                            y--;
                        }
                        else if(nums[x]+nums[y]<sum){
                            x++;
                        }
                        else{
                            y--;
                        }
                    }
                }
            }
            return vector<vector<int>>(uniqAns.begin(), uniqAns.end());
        }
    };


    int main(){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int target;
        cin>>target;

        Solution obj;
        vector<vector<int>> ans = obj.fourSum(nums, target);
        for(auto it: ans){
            for(auto i: it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }




    
// class Solution {
//     public:
//         vector<vector<int>> fourSum(vector<int>& nums, int target) {
//             int n = nums.size();
//             sort(nums.begin(), nums.end());
//             set<vector<int>> set;
//             vector<vector<int>> output;
//             for(int i=0; i<n-3; i++){
//                 for(int j=i+1; j<n-2; j++){
//                     long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
//                     int low = j+1, high = n-1;
//                     while(low < high){
//                         if(nums[low] + nums[high] < newTarget){
//                             low++;
//                         }
//                         else if(nums[low] + nums[high] > newTarget){
//                             high--;
//                         }
//                         else{
//                             set.insert({nums[i], nums[j], nums[low], nums[high]});
//                             low++; high--;
//                         }
//                     }
//                 }
//             }
//             for(auto it : set){
//                 output.push_back(it);
//             }
//             return output;
//         }
//     };
    
    
    
    