// Last updated: 4/7/2025, 7:13:39 PM
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
    // The right child gets assigned a min (the parent)
    // The left child gets assigned a max (the parent)

    // Recurse on a helper function
    bool isValidBSTHelper(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->left != nullptr && (root->left->val <= min || root->left->val >= root->val)) {
            return false;
        }
        if (root->right != nullptr && (root->right->val >= max || root->right->val <= root->val)) {
            return false;
        } 

        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};