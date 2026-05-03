class Solution {
public:
    int maxSum = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info dfs(TreeNode* root) {
        // Base case
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check if current subtree is BST
        if (left.isBST && right.isBST &&
            root->val > left.maxVal && root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;

            // Update global max
            maxSum = max(maxSum, currSum);

            return {
                true,
                currSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};