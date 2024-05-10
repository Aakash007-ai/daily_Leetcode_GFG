#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int> &nums,int s,int mid,int e){
        //we have s and e different all are inclusive
        //so creating a new vector then 
        vector<int> temp;
        int i=0;
        int x=s,y=mid+1;
        //assume two pointer x and y pointing to 2 sorted array  and we just have to merge them
        //so there will be some edge cases, either we traverse first vector complete then we just have to copy other elements
        //assume 2 cases [a,b] [c,d] ans can be abcd , cdab ,acbd ,cadb
        while(x<=mid || y<=e){//both are inclusive
            if(y <= e && x<=mid && nums[y] <= nums[x]){ //nums[y] is smaller put that in vector
                temp.push_back(nums[y++]);
            }else{
                if(x>mid){
                    temp.push_back(nums[y++]);
                }else{
                    temp.push_back(nums[x++]);
                }
          
            }
        }
        int k=0;
        for(int i=s;i<=e;i++){
            //push in nums
            nums[i]=temp[k];
        }
        
    }

    void mergeSort(vector<int> &nums,int s,int e){
        //divide and merge
        if(s>=e) return;

        int mid=s + (e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

int main(){
    vector<int> arr = {5,2,3,1};
    Solution obj;
    vector<int> ans=obj.sortArray(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
}