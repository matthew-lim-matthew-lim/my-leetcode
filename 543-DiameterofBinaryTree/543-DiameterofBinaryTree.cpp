// Last updated: 3/31/2025, 2:11:54 AM
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
    int traverse(TreeNode* root, int &biggest) {
        int left = root->left == nullptr ? 0 : traverse(root->left, biggest) + 1;
        int right = root->right == nullptr ? 0 : traverse(root->right, biggest) + 1;

        biggest = max(biggest, left + right);

        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Biggest height of left and right
        if (root == nullptr) {
            return 0;
        }

        int biggest = 0;
        traverse(root, biggest);

        return biggest;
    }
};