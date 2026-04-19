class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxnum = INT_MIN;
            int minnum = INT_MAX;

            // max(nums[0..i])
            for (int j = 0; j <= i; j++) {
                maxnum = max(maxnum, nums[j]);
            }

            // min(nums[i..n-1])
            for (int j = i; j < n; j++) {
                minnum = min(minnum, nums[j]);
            }

            if (maxnum - minnum <= k) {
                return i;
            }
        }

        return -1;
    }
};