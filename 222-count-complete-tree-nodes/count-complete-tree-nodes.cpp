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

    int countNodes(TreeNode* root) {
        // Base case
        if(root == NULL) return 0;

        // Find left and right heights
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // If heights are equal → perfect binary tree
        if(lh == rh) {
            return (1 << lh) - 1;   // 2^lh - 1
        }

        // Else recursively count
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to find left height
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Function to find right height
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->right;
        }
        return height;
    }
};