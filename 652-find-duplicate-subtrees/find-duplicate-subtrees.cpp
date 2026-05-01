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
 unordered_map<string, int> mp;
 vector<TreeNode*> result;

 string solve(TreeNode* root) {
     if (!root) return "N";  // null marker
     
     // serialize left and right
     string left = solve(root->left);
     string right = solve(root->right);
     
     // create current subtree serialization
     string curr = to_string(root->val) + "," + left + "," + right;
     
     // count frequency
     mp[curr]++;
     
     // if seen exactly twice → duplicate
     if (mp[curr] == 2) {
         result.push_back(root);
     }
     
     return curr;
 }

 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
     solve(root);
     return result;
 }
};