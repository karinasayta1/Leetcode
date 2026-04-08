class Solution {
public:
    
    int helper(TreeNode* root, int &maxi) {
        if (!root) return 0;

        int left = max(0, helper(root->left, maxi));
        int right = max(0, helper(root->right, maxi));

        // Update global max path
        maxi = max(maxi, left + right + root->val);

        // Return path sum including this node
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};