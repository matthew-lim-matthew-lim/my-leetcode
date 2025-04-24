// Last updated: 4/25/2025, 2:16:23 AM
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
// Hmm tricky!
// Post-order traversal. 
    int postOrder(TreeNode* root, int &largestDiameter) {
        if (root == nullptr) {
            return -1;
        }

        int leftHeight = postOrder(root->left, largestDiameter) + 1;
        int rightHeight = postOrder(root->right, largestDiameter) + 1;
        largestDiameter = max(largestDiameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int largestDiameter = 0;
        int leftHeight = postOrder(root->left, largestDiameter) + 1;
        int rightHeight = postOrder(root->right, largestDiameter) + 1;
        return max(largestDiameter, leftHeight + rightHeight);
    }
};