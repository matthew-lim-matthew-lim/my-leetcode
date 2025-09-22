// Last updated: 9/23/2025, 1:38:01 AM
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        vector<int> res;

        res.push_back(root->val);
        q.push({ root, 0 });
        int currLevel = 0;
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            if (curr.second == currLevel) {
                res.back() = curr.first->val;
            } else {
                currLevel = curr.second;
                res.push_back(curr.first->val);
            }

            if (curr.first->left) {
                q.push({curr.first->left, curr.second + 1});
            }
            if (curr.first->right) {
                q.push({curr.first->right, curr.second + 1});
            }
        }

        return res;
    }
};