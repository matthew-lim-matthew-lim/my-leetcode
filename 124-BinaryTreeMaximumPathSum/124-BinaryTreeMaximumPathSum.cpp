// Last updated: 4/6/2025, 7:56:17 PM
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
    // The max path sum is the sum of the left path and right path, plus the current node. 
    // curr_path_sum = left + right + curr.
    // But the value you return is the max(left + curr, right + curr). 
    int dfs(TreeNode* root, int &currMax) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, currMax);
        int right = dfs(root->right, currMax);

        currMax = max(currMax, max(left, 0) + max(right, 0) + root->val);

        return max(max(left, 0) + root->val, max(right, 0) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int currMax = INT_MIN;
        dfs(root, currMax);

        return currMax;
    }

};