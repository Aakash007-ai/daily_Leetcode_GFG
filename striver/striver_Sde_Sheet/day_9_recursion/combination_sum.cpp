class Solution {
public:
    void solve(int n,vector<int> &candidate,set<vector<int>> &resultant,vector<int> currSet,int target){
        
        if(target == 0){
            resultant.insert(currSet);
            return;
        }
        
        if(n==0){
            return;
        }
        
        if(target >= candidate[n-1]){
            currSet.push_back(candidate[n-1]);
            solve(n,candidate,resultant,currSet,target-candidate[n-1]);
            currSet.pop_back();
        }

        solve(n-1,candidate,resultant,currSet, target);
        //we have no option to skip this element
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> result;

        solve(candidates.size(),candidates,result,{},target);

        return vector<vector<int>> (result.begin(),result.end());

    }
};