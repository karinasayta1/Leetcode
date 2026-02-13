class Solution {
public:

    void helper(int start, vector<int>&nums, vector<int> & current, vector<vector<int>> & result){

        result.push_back(current);

        for(int i = start; i<nums.size(); i++){

            if(i>start && nums[i]==nums[i-1]) continue; //to avoid duplicate for current recursion

            current.push_back(nums[i]);

            helper(i+1, nums, current, result);

            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        helper(0,nums,current,result);
        return result;
    }
};