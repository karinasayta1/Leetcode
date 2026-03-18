class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

    // Step 1: Count frequencies
    for (int num : nums) {
        freq[num]++;
    }

    int maxLength = 0;

    // Step 2: Check pairs (x, x+1)
    for (auto& it : freq) {
        int num = it.first;

        if (freq.count(num + 1)) {
            int length = it.second + freq[num + 1];
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
    }
};