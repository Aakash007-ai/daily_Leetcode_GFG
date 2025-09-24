class Solution {
public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int mxCount = 0;
            int count= 0;

            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    count=0;
                }else{
                    count++;
                    mxCount = max(mxCount,count);
                }
            }
            return mxCount;
        }
};