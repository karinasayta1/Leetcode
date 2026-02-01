class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
    if (n < 2) return 0; // less than 2 numbers, no gap

    // Step 1: find min and max
    int minNum = *min_element(nums.begin(), nums.end());
    int maxNum = *max_element(nums.begin(), nums.end());
    if (minNum == maxNum) return 0; // all numbers are same

    // Step 2: determine bucket size and number of buckets
    int bucketSize = max(1, (maxNum - minNum) / (n - 1)); // avoid 0
    int bucketCount = (maxNum - minNum) / bucketSize + 1;

    // Step 3: create buckets (store min and max in each)
    vector<int> bucketMin(bucketCount, INT_MAX);
    vector<int> bucketMax(bucketCount, INT_MIN);
    vector<bool> bucketUsed(bucketCount, false);

    for (int num : nums) {
        int idx = (num - minNum) / bucketSize;
        bucketMin[idx] = min(bucketMin[idx], num);
        bucketMax[idx] = max(bucketMax[idx], num);
        bucketUsed[idx] = true;
    }

    // Step 4: find max gap
    int maxGap = 0;
    int prevMax = minNum;

    for (int i = 0; i < bucketCount; i++) {
        if (!bucketUsed[i]) continue; // skip empty bucket
        maxGap = max(maxGap, bucketMin[i] - prevMax);
        prevMax = bucketMax[i];
    }

    return maxGap;
    }
};