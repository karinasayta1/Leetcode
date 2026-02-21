class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we will take 3 pointers low contains all 0s mid all 1s and hight all 2s
        int low = 0, mid = 0, high = nums.size()-1;

        while(mid <= high){

            if(nums[mid]==0){
               swap(nums[low], nums[mid]);
               low++;
               mid++; 
            }
            
            else if(nums[mid]==1){
                mid++;
            }

            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};