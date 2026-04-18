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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // Step 1: store inorder indices
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int preIndex = 0;
        
        return solve(preorder, inorder, preIndex, 0, inorder.size()-1, mp);
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int &preIndex, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {
        
        // Base case
        if(inStart > inEnd) return NULL;
        
        // Step 2: pick root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // Step 3: find root in inorder
        int pos = mp[rootVal];
        
        // Step 4: build left subtree
        root->left = solve(preorder, inorder, preIndex, inStart, pos - 1, mp);
        
        // Step 5: build right subtree
        root->right = solve(preorder, inorder, preIndex, pos + 1, inEnd, mp);
        
        return root;
    }
};