class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        // fix one number and go till n-2 Because  we need 3 elements. If only 2 elements remain, no triplet possible.
        for(int i = 0; i < n-2; i++){
            
            // skip duplicates
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            // to take next two elements we will use 2 pointers
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];

                if(sum==0){
                    result.push_back({nums[i], nums[left], nums[right]});

                    //skipping duplicate left
                    while(left < right && nums[left]==nums[left+1]){
                        left++;
                    }

                    //skipping duplicate right
                    while(left < right && nums[right]==nums[right-1]){
                        right--;
                    }

                    left++;
                    right--;

                }

                else if(sum<0){
                    left++;
                }
                else
                    right--;
            }
        }
        return result;
    }
};