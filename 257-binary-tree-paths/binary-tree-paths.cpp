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
//Iterative approach
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;

        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});

        while (!st.empty()) {
            auto [node, path] = st.top();
            st.pop();

            // If leaf node
            if (!node->left && !node->right) {
                result.push_back(path);
            }

            // Push right child first (so left is processed first)
            if (node->right) {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }

            // Push left child
            if (node->left) {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }

        return result;
    }
};