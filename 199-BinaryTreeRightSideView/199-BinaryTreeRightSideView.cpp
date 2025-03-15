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

// Really interesting/weird problem.
// Maybe use inorder traversal and update each level to the latest node. 

class Solution {
public:
    void traverse(TreeNode* root, vector<int> &res, int depth) {
        if (root == nullptr) {
            return;
        }

        if (depth < res.size()) {
            res[depth] = root->val;
        } else {
            res.push_back(root->val);
        }
        traverse(root->left, res, depth + 1);
        traverse(root->right, res, depth + 1); 
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        traverse(root, res, 0);

        return res;
    }
};