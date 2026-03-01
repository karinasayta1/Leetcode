class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> cumulativeSum(n + 1, 0); // n+1
        int result = INT_MAX;

        // build prefix sum properly
        for(int j = 0; j < n; j++){
            cumulativeSum[j + 1] = cumulativeSum[j] + nums[j];
        }

        for(int j = 0; j <= n; j++){

            // shrink from front if valid
            while(!dq.empty() && 
                  cumulativeSum[j] - cumulativeSum[dq.front()] >= k){
                result = min(result, j - dq.front());
                dq.pop_front();
            }

            // maintain monotonic increasing prefix
            while(!dq.empty() && 
                  cumulativeSum[j] <= cumulativeSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return result == INT_MAX ? -1 : result;
    }
};