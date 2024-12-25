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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        // Level order traversal using a queue
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });

        vector<int> res; 

        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();

            if (res.size() <= curr.second) res.push_back(INT_MIN);
            res[curr.second] = max(res[curr.second], curr.first->val);

            if (curr.first->left != nullptr) q.push({ curr.first->left, curr.second + 1 });
            if (curr.first->right != nullptr) q.push({ curr.first->right, curr.second + 1 });
        }

        return res;
    }
};