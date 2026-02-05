class Solution {
public:
    void solve(int start, vector<int>& candidates, int remaining_sum, vector<int> & current, vector<vector<int>> & result ){
        
        if(remaining_sum==0){
            result.push_back(current);
            return;
        }

        if(remaining_sum<0){
            return;
        }

        for(int i = start; i<candidates.size(); i++){
            current.push_back(candidates[i]);
            solve(i, candidates, remaining_sum - candidates[i], current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        solve(0, candidates, target, current, result);
        return result;
    }
};