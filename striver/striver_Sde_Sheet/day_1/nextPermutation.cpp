#include<bits/stdc++.h>
using namespace std;

// next permutation 
// it is just a next lexicographically character
/**
 *  so we traverse from back , then start comparing we stop when we found element which is smaller from rest max
 * 
 * 1 2 3 6 5 4
 * 1 2 4 3 5 6
 * 
*/

class Solution {
public:
    // void nextPermutation(vector<int>& nums) {
    //     int n = nums.size(); 
    //     int i = nums.size()-1;
    //     int maxEle = INT_MIN;
    //     int maxIdx = i;
    //     maxEle = max(maxEle,nums[i]);
    //     while(i-->=0){
    //         if(nums[i] < nums[i+1]){
    //             break;
    //         }else if(maxEle < nums[i]){
    //             maxEle = nums[i];
    //             maxIdx = i;
    //         }
    //     }
    //     if(i < 0 ){
    //         reverse(nums.begin(),nums.end());
    //         return;
    //     }

    //     int nextGr = nums[i];
    //     int nGIdx = maxIdx;
    //     int j=i;
    //     while(j++<n){
    //         if(nums[j]>nums[i]){
    //             if(nums[j] <= nextGr){
    //                 nGIdx = j;
    //             }
    //         }
    //     }
    //     swap(nums[i],nums[j]);
    //         //find next greatest element
    //         // swap(nums[i],nums[minIdx]);
    //     sort(nums.begin()+i+1, nums.end());
        
    // }


    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i; 
                break;
            }
        }

        for(int i=n-1; index!= -1 , i> index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
    }

    void printVector(vector<int> &nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> sam = {3,2,1};
    // cout<<"printing array"<<endl;
    Solution obj = Solution();
    obj.printVector(sam);
    obj.nextPermutation(sam);
    obj.printVector(sam);

}