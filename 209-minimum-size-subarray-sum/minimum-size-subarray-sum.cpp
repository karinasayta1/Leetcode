class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, right = 0, sum = 0;

        for(int left = 0; left<nums.size(); left++){
            sum += nums[left];

               while(sum >= target){
                   ans = min(ans, left-right+1);
                   sum -= nums[right];
                   right++;
               }
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};