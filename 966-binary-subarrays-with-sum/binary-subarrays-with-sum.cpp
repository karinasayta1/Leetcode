class Solution {
public:

    int atmost(vector<int>& nums, int goal){
        int l = 0, r = 0, sum = 0, count = 0;
        
        //edge case 
        if(goal<0) return 0;

       for(int r = 0; r<nums.size(); r++){
            sum += nums[r];
            
            //shrink window if sum > goal
            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            count += (r-l+1);
        }
         return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};