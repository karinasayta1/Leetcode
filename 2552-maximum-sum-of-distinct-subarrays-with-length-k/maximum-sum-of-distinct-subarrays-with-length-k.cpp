class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> st;
    long long sum = 0, maxSum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {

        // remove elements until nums[right] becomes distinct
        while (st.count(nums[right])) {
            st.erase(nums[left]);
            sum -= nums[left];
            left++;
        }

        // add current element
        st.insert(nums[right]);
        sum += nums[right];

        // keep window size k
        if (right - left + 1 == k) {
            maxSum = max(maxSum, sum);

            // slide window
            st.erase(nums[left]);
            sum -= nums[left];
            left++;
        }
    }

    return maxSum;
    }
};