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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int postIndex = inorder.size() - 1;
        
        return solve(postorder, inorder, postIndex, 0, inorder.size() - 1, mp);
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,
                    int &postIndex, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {
        
        // Base case
        if(inStart > inEnd) return NULL;
        
        // Pick root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root in inorder
        int pos = mp[rootVal];
        
        // IMPORTANT: build right first
        root->right = solve(postorder, inorder, postIndex, pos + 1, inEnd, mp);
        root->left  = solve(postorder, inorder, postIndex, inStart, pos - 1, mp);
        
        return root;
    }
};