class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i<nums.size(); i++){

            int x = nums[i];
            int tempmax = maxprod;

            maxprod = max(x, max(maxprod * x, minprod * x));
            minprod = min(x, min(tempmax * x, minprod * x));

            ans = max(ans,maxprod);
        }
        return ans;
    }
};