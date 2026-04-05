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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        // if left is null then go right
        if(root->left == NULL){
            return minDepth(root->right)+1;
        }

        //if right is null then go left
        if(root->right == NULL){
            return minDepth(root->left)+1;
        }

        // if both left and right exist
        int left = minDepth(root->left);   
        int right = minDepth(root->right); 
        
        return min(left, right) + 1; 
    }
    
};