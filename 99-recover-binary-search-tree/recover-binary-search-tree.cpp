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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                detect(curr);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;

                // Find inorder predecessor
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;   // create thread
                    curr = curr->left;
                } else {
                    pred->right = nullptr; // remove thread
                    detect(curr);
                    curr = curr->right;
                }
            }
        }

        // swap the two nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void detect(TreeNode* curr) {
        if (prev && prev->val > curr->val) {
            if (!first) first = prev;
            second = curr;
        }
        prev = curr;
    }
};