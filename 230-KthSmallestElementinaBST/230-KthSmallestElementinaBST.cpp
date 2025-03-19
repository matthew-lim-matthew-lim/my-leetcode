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
    void traverse(TreeNode* root, int &k, int &ele) {
        if (root->left != nullptr) {
            traverse(root->left, k, ele);
        }
        k--;
        if (k == 0) {
            ele = root->val;
        }
        if (root->right != nullptr) {
            traverse(root->right, k, ele);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        // In order traverse and keep track of the kth element
        int ele = 0;
        traverse(root, k, ele);

        return ele;
    }
};