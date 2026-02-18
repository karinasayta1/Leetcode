class Solution {
public:

    int atmost(vector<int>& nums, int k){
        int l = 0, sum = 0, count = 0;

        // edge case 
        if(k<0) return 0;

        for(int r = 0 ; r<nums.size(); r++){

            sum += nums[r];

            //shrink window if sum>k
            while(sum > k){
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i]%2 == 0)
                nums[i]=0;
            else
                nums[i]=1;
        }

        return atmost(nums, k) - atmost(nums, k-1);
    }
};