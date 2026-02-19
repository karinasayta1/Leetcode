class Solution {
public:

    int atmost(vector<int>& nums, int k){
        int l = 0, count = 0;
        unordered_map<int,int> freq;

        // edge case
        if(k < 0) return 0;

        for(int r = 0; r < nums.size(); r++){

            freq[nums[r]]++;

            // if new element added
            if(freq[nums[r]] == 1){
                k--;
            }

            // shrink window if distinct > k
            while(k < 0){
                freq[nums[l]]--;

                if(freq[nums[l]] == 0){
                    k++;
                }

                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};
