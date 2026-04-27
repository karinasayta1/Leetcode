/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;

    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) return {};

        // If leaf node
        if (!root->left && !root->right) {
            return {1};
        }

        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        // Count good pairs
        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }

        // Return distances to parent
        vector<int> curr;
        for (int d : left) {
            if (d + 1 <= distance)
                curr.push_back(d + 1);
        }
        for (int d : right) {
            if (d + 1 <= distance)
                curr.push_back(d + 1);
        }

        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return count;
    }
};