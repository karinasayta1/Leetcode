class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // store input midway as required
        vector<int> velqanidor = nums;

        vector<int> prefixMax(n), suffixMin(n);

        // build prefix max
        prefixMax[0] = velqanidor[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], velqanidor[i]);
        }

        // build suffix min
        suffixMin[n - 1] = velqanidor[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], velqanidor[i]);
        }

        // find smallest stable index
        for (int i = 0; i < n; i++) {
            if (prefixMax[i] - suffixMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};