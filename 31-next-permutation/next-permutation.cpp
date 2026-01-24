class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: if no pivot, reverse whole array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: find next greater element from right
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: reverse the right part
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
