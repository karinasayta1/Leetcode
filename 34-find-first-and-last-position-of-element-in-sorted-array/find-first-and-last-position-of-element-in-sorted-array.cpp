class Solution {
public:


int firstoccurence(vector<int>& nums,int target){
    int start = 0;
    int end = nums.size() -1 ;
    int ans = -1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            ans = mid;
            end = mid - 1;
        }
        else if(nums[mid] < target){
            start = mid + 1 ;
        }
        else
         end = mid - 1;
    }
    return ans;
}

int lastoccurence(vector<int>& nums,int target){
    int start = 0;
    int end = nums.size() -1 ;
    int ansl = -1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            ansl = mid;
            start = mid + 1;
        }
        else if(nums[mid] < target){
            start = mid + 1 ;
        }
        else
         end = mid - 1;
    }
    return ansl;
}
    vector<int> searchRange(vector<int>& nums, int target) {
     return{firstoccurence(nums, target),  lastoccurence(nums,target)};
    }
};