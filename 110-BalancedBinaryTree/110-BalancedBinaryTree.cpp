// Last updated: 4/7/2025, 6:20:56 PM
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
    // Recursively determine if the height of each child node differs only by 1.
    int postOrderDFS(TreeNode* root, bool &valid) {
        if (root == nullptr) {
            return 0;
        }

        int left = postOrderDFS(root->left, valid) + 1;
        int right = postOrderDFS(root->right, valid) + 1;

        if (abs(left - right) > 1) {
            valid = false;
        }

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool valid = true;

        postOrderDFS(root, valid);

        return valid;
    }
};