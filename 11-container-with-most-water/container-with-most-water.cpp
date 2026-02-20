class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0 ,l = 0, r = height.size()-1;

        while(l < r){
            int w = r - l;
            int ht = min(height[r], height[l]);
            int currWater = w * ht;

            maxWater = max(maxWater, currWater);

            height[l] < height[r] ? l++: r--;
        }

        return maxWater;
    }
};