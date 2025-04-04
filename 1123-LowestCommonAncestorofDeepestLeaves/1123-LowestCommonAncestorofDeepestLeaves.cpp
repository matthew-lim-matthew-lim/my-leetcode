// Last updated: 4/4/2025, 1:37:43 PM
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
    // Returns a pair: {height, LCA of this subtree}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root)
            return {0, nullptr};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left.first == right.first) {
            // Current node is the LCA
            return {left.first + 1, root};
        } else if (left.first > right.first) {
            // Left side is deeper
            return {left.first + 1, left.second};
        } else {
            // Right side is deeper
            return {right.first + 1, right.second};
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
