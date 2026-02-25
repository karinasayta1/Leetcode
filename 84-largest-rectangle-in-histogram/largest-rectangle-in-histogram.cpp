class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     int n = heights.size();
    stack<int> st;   // stores indices
    int maxArea = 0;

    for(int i = 0; i <= n; i++) {
        
        // Treat last as 0 height to flush stack
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            
            int height = heights[st.top()];
            st.pop();
            
            int width;
            
            if(st.empty()) {
                width = i;  
            } else {
                width = i - st.top() - 1;
            }
            
            maxArea = max(maxArea, height * width);
        }
        
        st.push(i);
    }

    return maxArea;   
    }
};