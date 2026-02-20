class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeroscount = 0, maxlength= INT_MIN, left = 0;

        for(int right = 0; right<n; right++){

            if(nums[right]==0){
                zeroscount++;
            }

            //shrink window if zeros exceeds k
            while(zeroscount > k){
                if(nums[left] == 0){
                    zeroscount--;
                }
                left++;
            }

            maxlength=max(maxlength, right - left + 1);

        }  
        return maxlength;
    }
};