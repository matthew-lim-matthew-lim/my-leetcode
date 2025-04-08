// Last updated: 4/9/2025, 12:32:10 AM
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
    int traverse(TreeNode* root, int largest) {
        if (root == nullptr) {
            return 0;
        }
        largest = max(largest, root->val);

        return (largest == root->val) + traverse(root->left, largest) + traverse(root->right, largest);
    }

    int goodNodes(TreeNode* root) {
        // Definitely pre-order traversal, keeping track of the largest node seen so far.
        return traverse(root, root->val);
    }
};