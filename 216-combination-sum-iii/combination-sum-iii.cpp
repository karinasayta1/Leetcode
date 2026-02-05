class Solution {
public:
    void solve(int start, int k, int remaining_sum,vector<int> & current, vector<vector<int>>& result){
        if(current.size()==k && remaining_sum == 0){
            result.push_back(current);
            return;
        }
        if(current.size() > k || remaining_sum < 0) {
            return;
        }

        for(int i = start; i<=9; i++){
            current.push_back(i);
            solve(i+1, k, remaining_sum - i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        vector<vector<int>> result;
        int remaining_sum=n;
        solve(1, k, remaining_sum,current, result);
        return result;
    }

};