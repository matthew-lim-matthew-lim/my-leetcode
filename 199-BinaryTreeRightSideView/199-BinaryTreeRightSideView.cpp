// Last updated: 4/9/2025, 12:24:35 AM
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
        // BFS works best for this because it goes level by level. 
        // Just make sure that BFS does the left child before the right child each time.
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        int prev_level = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 0 });
        while(!q.empty()) {
            pair<TreeNode*, int> curr_p = q.front();
            q.pop();

            TreeNode* currNode = curr_p.first;
            int currLevel = curr_p.second;
            if (currLevel != prev_level) {
                prev_level = currLevel;
                res.push_back(currNode->val);
            } else {
                res.back() = currNode->val;
            }

            if (currNode->left != nullptr) {
                q.push({ currNode->left, currLevel + 1 });
            } 
            if (currNode->right != nullptr) {
                q.push({ currNode->right, currLevel + 1 });
            } 
        }
        
        return res;
    }
};