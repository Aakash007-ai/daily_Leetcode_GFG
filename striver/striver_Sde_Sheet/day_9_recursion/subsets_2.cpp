class Solution {
public:
         void subsets(int index, set<vector<int>>& resultSet,vector<int>currentSet, vector<int>& nums){
            if(index ==nums.size()){
                sort(currentSet.begin(), currentSet.end());
                resultSet.insert(currentSet);
                return;               
            }

            //exculding the current element
            subsets(index+1,resultSet,currentSet,nums);
            //including the current element
            currentSet.push_back(nums[index]);
            subsets(index+1,resultSet,currentSet,nums);

        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            set<vector<int>> resultSet;
            vector<int> currentSet;

            subsets(0,resultSet,currentSet,nums);
            vector<vector<int>> result(resultSet.begin(), resultSet.end());
            return result;

        }
};